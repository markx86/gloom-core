#ifndef FB_H_
#define FB_H_

#include <gloom/types.h>
#include <gloom/macros.h>

#define FB_WIDTH  640
#define FB_HEIGHT 480

struct fb {
  u32* pxls;
  u32 stride;
};

extern struct fb _g_fb;
extern f32 _g_zbuf[FB_WIDTH];

static inline
u32 _fb_offset(u32 x, u32 y) {
  return x + y * _g_fb.stride;
}

static inline
void fb_set_pixel(u32 x, u32 y, u32 c) {
  _g_fb.pxls[_fb_offset(x, y)] = c;
}

static inline
u32 fb_get_pixel(u32 x, u32 y) {
  return _g_fb.pxls[_fb_offset(x, y)];
}

static inline
void zb_set_depth(u32 x, f32 depth) {
  _g_zbuf[x] = depth;
}

static inline
f32 zb_get_depth(u32 x) {
  return _g_zbuf[x];
}

#endif
