#include <nds.h>

#include "main.h"
#include "textures.h"

#include "Shop_Floor_pcx.h"

int textures[TEXTURE_LENGTH];

int load_textures()
{
  glEnable(GL_TEXTURE_2D);

  if (!glGenTextures(2, textures)) return FALSE;

  load_texture(SHOP_FLOOR_TEXT, Shop_Floor_pcx);

  return TRUE;
}

int load_texture(texture_id_t id, const uint8_t pcx_data[])
{
  sImage pcx;
  if (!loadPCX((u8 *)pcx_data, &pcx)) return FALSE;
  image8to16(&pcx);

  glBindTexture(0, textures[id]);
  if (!glTexImage2D(0, 0, GL_RGB,
    TEXTURE_SIZE_32, TEXTURE_SIZE_32, 0,
    TEXGEN_TEXCOORD | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T,
    pcx.image.data8)) return FALSE;

  glBindTexture(0, 0);
  imageDestroy(&pcx);

  return TRUE;
}
