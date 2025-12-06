#include <gloom/client.h>
#include <gloom/gloom.h>
#include <gloom/ui.h>

#define BACKGROUND_COLOR SOLID_COLOR(RED)
#define FOREGROUND_COLOR SOLID_COLOR(WHITE)

static struct component g_quit = {
  .type = UICOMP_BUTTON, .text = "> quit", .on_click = gloom_exit
};

static
void on_enter(void) {
  ui_set_colors(FOREGROUND_COLOR, BACKGROUND_COLOR);
  ui_clear_screen();

  ui_draw_title(32, 32, "disconnected");
  ui_draw_string(48, 32 + TITLE_HEIGHT,
                 "a fatal error occurred, you've been disconnected");
  ui_on_enter(&g_quit, 1);
}

static
void on_tick(f32 delta) {
  UNUSED(delta);
  ui_draw_component(48, FB_HEIGHT - 32 - STRING_HEIGHT, &g_quit);
}

static
void on_mouse_moved(u32 x, u32 y, i32 dx, i32 dy) {
  ui_on_mouse_moved(x, y, dx, dy, &g_quit, 1);
}

static
void on_mouse_up(u32 x, u32 y, u32 button) {
  UNUSED(button);
  ui_on_mouse_up(x, y, &g_quit, 1);
}

static
void on_mouse_down(u32 x, u32 y, u32 button) {
  UNUSED(button);
  ui_on_mouse_down(x, y, &g_quit, 1);
}

const struct state_handlers g_error_state = {
  .on_enter = on_enter,
  .on_tick = on_tick,
  .on_mouse_moved = on_mouse_moved,
  .on_mouse_up = on_mouse_up,
  .on_mouse_down = on_mouse_down
};
