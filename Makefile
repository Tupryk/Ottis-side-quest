all:
	g++ -Wall -Iinclude src/main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o p -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 src/app.cpp src/engineUI.cpp src/Physics/physics.cpp src/Entities/block.cpp src/Graphics/sprites.cpp src/World/game.cpp src/World/scene.cpp src/World/chapter.cpp src/Graphics/camera.cpp src/Entities/player.cpp src/Entities/background.cpp src/Entities/npc.cpp src/utils.cpp src/Interactions/indicators.cpp src/Entities/character.cpp src/Graphics/debug_utils.cpp src/Interactions/chat.cpp src/Graphics/text.cpp src/Entities/items.cpp src/Graphics/particles.cpp src/Entities/objects.cpp src/ReadObjects/read_objs.cpp

clean:
	rm p