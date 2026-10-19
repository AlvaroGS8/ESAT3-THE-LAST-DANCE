
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/window.h>

#include <esat_extra/imgui.h>
#include <loader.h>

int esat::main(int argc, char** argv) {
  esat::WindowInit(1280, 720);

  esat::WindowSetMouseVisibility(true);

  Board MyBoard;
  MyBoard.init(120, 88);
  BoardFromImage(&MyBoard, "data/gfx/maps/map_03_120x88_cost.png");

  for(int i = 0; i<MyBoard.height_; ++i){
      for(int j = 0; j<MyBoard.width_; ++j){
        if(MyBoard.cell(i,j).value == kTileType_Normal){
            printf(" ");
        } else if(MyBoard.cell(i,j).value == kTileType_Wall){
            printf("#");
        }
      }
	  printf("\n");
	}

  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    
    esat::DrawEnd();

    ImGui::Render();


    // End of current frame
    esat::WindowFrame();  
  }

  esat::WindowDestroy();

  return 0;
}

