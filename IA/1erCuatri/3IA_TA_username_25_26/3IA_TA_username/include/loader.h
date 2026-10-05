#ifndef __LOADER_H__
#define __LOADER_H__ 1

#include "board.h"
#include "common_def.h"

#include <esat/sprite.h>

// Load a cost map image where:
// - White pixel: walkable
// - Black pixel: non-walkable
static ErrorCode BoardFromImage(Board* board, const char* filename) {
  if (filename == nullptr) return kErrorCode_SRCNullPointer;
  if (board == nullptr) return kErrorCode_DataNullPointer;

  esat::SpriteHandle handle = esat::SpriteFromFile(filename);
  if (handle == nullptr) return kErrorCode_File;

  board->init(esat::SpriteWidth(handle), esat::SpriteHeight(handle)); 

  for (int col = 0; col < esat::SpriteWidth(handle); ++col) {
    for (int row = 0; row < esat::SpriteHeight(handle); ++row) {
      unsigned char outRGBA[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
      esat::SpriteGetPixel(handle, col, row, outRGBA);
      if ((outRGBA[0] == 0xFF) && 
          (outRGBA[1] == 0xFF) && 
          (outRGBA[2] == 0xFF)) {
        // White
        board->cell(row, col).value = kTileType_Normal;
      } else if (
          (outRGBA[0] == 0x00) && 
          (outRGBA[1] == 0x00) && 
          (outRGBA[2] == 0x00)) {
        // Black
        board->cell(row, col).value = kTileType_Wall;
      } else {
        board->cell(row, col).value = kTileType_Wall;
      }
    }
  }
}

#endif
