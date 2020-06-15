#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Main loop
int main(){

  // Window Init
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Collision Test");

  // Rectangle
  Rectangle Rect = {SCREEN_WIDTH / 2 - 200,
		    SCREEN_HEIGHT / 2 - 50,
		    200, 100};

  // Cube
  Color CUBE_COLOR = GREEN;
  Rectangle Cube = {SCREEN_WIDTH / 2 - 25,
		    SCREEN_HEIGHT / 2 - 25,
		    50, 50};
  float speed = 5.0f;

  
  bool is_colliding;

  while(!WindowShouldClose()){

    // Update Section

    is_colliding = CheckCollisionRecs(Cube,Rect);

    if (is_colliding){
      CUBE_COLOR = YELLOW;
    }else{
      CUBE_COLOR = GREEN;
    }
    

    // Cube movement controls

    if ( IsKeyDown(KEY_RIGHT)){
      Cube.x += speed;
    }else if(IsKeyDown(KEY_LEFT)){
	Cube.x -= speed;
      }

    if (IsKeyDown(KEY_UP)){
      Cube.y -= speed;
    }else if(IsKeyDown(KEY_DOWN)){
      Cube.y += speed;
    }
    
    // Drawing Section

    BeginDrawing();
    ClearBackground(GRAY);

    DrawRectangleRec(Rect,RED);
    DrawRectangleRec(Cube,CUBE_COLOR);
    
    DrawText(TextFormat("Is Colliding: %d",is_colliding), // 0 for false
	     10,10,20,BLACK);                             // 1 for true

    
    EndDrawing();

  }
  
  CloseWindow();
  return 0; // OK
}
