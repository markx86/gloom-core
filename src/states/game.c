#include <gloom/client.h>
#include <gloom/game.h>
#include <gloom/multiplayer.h>
#include <gloom/globals.h>
#include <gloom/color.h>
#include <gloom/libc.h>

static b8 g_do_send_update;

static
void on_enter(void) {
  if (!client_pointer_is_locked())
    platform_pointer_lock();

  color_set_alpha(0xFF);
  g_do_send_update = false;
}

static
void on_tick(f32 delta) {
  if (g_do_send_update) {
    multiplayer_send_update();
    g_do_send_update = false;
  }
  game_tick(delta);
}

static
void on_analog_change(f32 x, f32 y) {
  if (!client_pointer_is_locked())
    return;

  game_analog_set(x, y);

  multiplayer_queue_input();
  g_do_send_update = true;
}

static
void on_mouse_moved(u32 x, u32 y, i32 dx, i32 dy) {
  UNUSED(x);
  UNUSED(y);
  UNUSED(dy);

  if (!client_pointer_is_locked())
    return;

  game_player_add_rot(dx * g_mouse_sensitivity * PLAYER_ROT_SPEED);

  g_do_send_update = true;
}

static
void on_mouse_down(u32 x, u32 y, u32 button) {
  UNUSED(button);
  UNUSED(x);
  UNUSED(y);

  if (!client_pointer_is_locked()) {
    platform_pointer_lock();
    return;
  }

  multiplayer_fire_bullet();
}

const struct state_handlers g_game_state = {
  .on_enter = on_enter,
  .on_tick = on_tick,
  .on_analog_change = on_analog_change,
  .on_mouse_moved = on_mouse_moved,
  .on_mouse_down = on_mouse_down,
};
