/// @brief Agent class definition
/// @author Gustavo Aranda <garanda@esat.es>
#ifndef __AGENT_H__
#define __AGENT_H__ 1

#include <stdint.h>

#include "common_def.h"

enum Direction {
  kDirection_North,
  kDirection_East,
  kDirection_South,
  kDirection_West,
  kDirection_None
};

enum MovementType {
  kMovementType_Random,
  kMovementType_Pacman,
  kMovementType_None
};

struct Agent {
  Agent();

  int32_t id;
  Direction dir;
  MovementType move_type;
  int32_t target_idx;
};

#endif

