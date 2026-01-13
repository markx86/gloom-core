#include <gloom/fb.h>
#include <gloom/gloom.h>

struct fb _g_fb;

void gloom_framebuffer_set(void* fb, void* zb, u32 stride) {
  _g_fb = (struct fb) {
    .pxls = fb,
    .zbuf = zb,
    .stride = stride
  };
}

u32 gloom_framebuffer_width(void) {
  return FB_WIDTH;
}

u32 gloom_framebuffer_height(void) {
  return FB_HEIGHT;
}
