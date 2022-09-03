class levelOne
{
public:
	void play();
private:
	BackroundImg backroundImg;
    Backround backround;
    Player dog;
    Person person;
    Ball ball;
    Boat boat;
    Cat cat;
    Clouds clouds;

    BloodParticles blood;
    SewerParticles drops;
    SandParticles sand;

    Plataform plataform;
    bool init = false;

    StaticBox boxes[1];
};

void levelOne::play()
{
	if (!init)
	{
	    backroundImg.init();
	    backround.init();
	    dog.init();
	    person.init();
	    ball.init();
	    boat.init();
        cat.init();
        clouds.init();
        plataform.init();
        
        drops.size[0] = 32;
        drops.size[1] = 150;
        drops.Position[0] = 596;
        drops.Position[1] = 145;
        drops.init();

        blood.size[0] = 128;
        blood.size[1] = 128;
        blood.init();

        sand.size[0] = 64;
        sand.size[1] = 32;
        sand.init();

	    window.setView(camera);

	    init = true;

        boxes[0].Dimensions[0] = -ScreenWidth*0.5;
        boxes[0].Dimensions[1] = 140;
        boxes[0].Position[0] = LevelLength;
        boxes[0].Position[1] = 160;
        boxes[0].Type = "Sand";
	}
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        std::cout << "x: " << (sf::Mouse::getPosition(window).x/2)+PlayerPosX-(ScreenWidth*0.5) << std::endl;
        std::cout << "y: " << sf::Mouse::getPosition(window).y/2-(ScreenHeight*0.5) << std::endl;
    }
    dog.update();
    PlayerPosX = dog.PositionX;
    PlayerPosY = dog.PositionY;
    ball.update(person.FrameIndex);
    drops.update();
    blood.update();
    clouds.update();
	CameraMovement(LevelLength);

    backroundImg.draw();





    //Things That can get Picked Up
    dog.PickUp(dog.NextToThing(ball.Pos[0], ball.Pos[1]), "Ball");
    //-------------------//






    if (dog.ObjGrabbed == "Ball")
    {
        dog.UpdateMouthPosition();
        if (!dog.LookingRight) {
            ball.Pos[0] = PlayerPosX-dog.mouthPos[0]-2;
        } else {
            ball.Pos[0] = PlayerPosX+dog.mouthPos[0];
        }
        ball.Pos[1] = PlayerPosY + dog.mouthPos[1];
        ball.Vel[0] = dog.Vel[0];
        ball.Vel[1] = dog.Vel[1];
    }






    if (ball.Pos[0] < -60 && ball.Pos[0] > -100 && !person.PickingUpBall && dog.ObjGrabbed != "Ball" && person.Waiting && !person.ThrowingBall && !ball.Grabbed && ball.Pos[1] == 138)
    {
        ball.Grabbed = true;
        person.PickingUpBall = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && ball.Grabbed)
    {
        person.ThrowingBall = true;
    }







    backround.draw();
    clouds.draw();
    boat.draw();
    person.draw();
    //plataform.drawBack();
    cat.draw();
    dog.draw();
    //plataform.drawFront();
    //drops.draw();
    ball.draw();
    blood.Position[0] = dog.PositionX;
    blood.Position[1] = dog.PositionY;

    if (dog.Vel[0] > 1.6 && dog.OnFloor)
    {
        sand.update(-1);
        sand.Position[0] = dog.PositionX-8;
        sand.Position[1] = dog.PositionY+5;
        sand.draw();
    }
    else if (dog.Vel[0] < -1.6 && dog.OnFloor)
    {
        sand.update(1);
        sand.Position[0] = dog.PositionX+8;
        sand.Position[1] = dog.PositionY+5;
        sand.draw();
    }
    blood.draw();

    if (!cat.interactionButton.activated) {
        dog.move();
    } else {
        dog.accx = 0;
    }
}