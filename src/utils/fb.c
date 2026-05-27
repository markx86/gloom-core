#include <gloom/fb.h>
#include <gloom/gloom.h>

struct fb _g_fb;
f32 _g_zbuf[FB_WIDTH];

void gloom_framebuffer_set(void* fb, u32 stride) {
  _g_fb = (struct fb) {
    .pxls = fb,
    .stride = stride
  };
}

u32 gloom_framebuffer_width(void) {
  return FB_WIDTH;
}

u32 gloom_framebuffer_height(void) {
  return FB_HEIGHT;
}
