
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/window.h>

#include <esat_extra/imgui.h>
#include <loader.h>

int esat::main(int argc, char** argv) {
  esat::WindowInit(1280, 720);

  esat::WindowSetMouseVisibility(true);

  Board MyBoard;

  ErrorCode e = BoardFromImage(&MyBoard, "data/gfx/maps/map_03_60x44_cost.png");

  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    esat::DrawEnd();

    ImGui::Render();

    if (e == kErrorCode_Ok) printf("OK");

    // End of current frame
    esat::WindowFrame();  
  }

  esat::WindowDestroy();

  return 0;
}

