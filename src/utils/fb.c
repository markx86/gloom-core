#include <gloom/fb.h>
#include <gloom/gloom.h>

struct fb _g_fb;

void gloom_set_framebuffer(void* fb, void* zb,
                           u32 width, u32 height, u32 stride) {
  _g_fb = (struct fb) {
    .pxls = fb,
    .zbuf = zb,
    .width = width,
    .height = height,
    .stride = stride
  };
}
