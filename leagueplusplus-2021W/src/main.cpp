#include "Engine.hpp"
#include "Sprite.hpp"
#include "HUD.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>


int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
		
	}


	std::string dump_arg;


	if(argc>0)
	{
  	  dump_arg.assign(argv[1]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);


	// Make a banana and add to scene. Should update and draw.
	Sprite* b = new Sprite(dump_arg);
	one.addUpdateable(b);
	one.addDrawable(b);
	auto b_up = [b](double delta) { b->up(delta); };
	auto b_down = [b](double delta) { b->down(delta); };
	auto b_left = [b](double delta) { b->left(delta); };
	auto b_right = [b](double delta) { b->right(delta); };
	one.addKeyEvent( SDLK_w, b_up );
	one.addKeyEvent( SDLK_a, b_left );
	one.addKeyEvent( SDLK_d, b_right );
	one.addKeyEvent( SDLK_s, b_down );

	// Add the HUD
	HUD* h = new HUD();
	one.addUpdateable(h);
	one.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();
}
