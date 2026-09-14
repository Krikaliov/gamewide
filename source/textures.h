#ifndef TEXTURES_H
#define TEXTURES_H 1

#include <stdint.h>

#define TEXTURE_LENGTH 1

typedef enum texture_id_t texture_id_t;
enum texture_id_t
{
  SHOP_FLOOR_TEXT
};

extern int textures[TEXTURE_LENGTH];

/**
 * Load all textures of the game.
 * @warning This must be called only once per execution.
 */
int load_textures();

int load_texture(texture_id_t, const uint8_t[]);

#endif // TEXTURES_H
