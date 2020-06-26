#include<iostream>
#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;
using namespace sf;

void ludo_board()
{
	srand(time(0));
	bool uperaagye=false;
	int roll;
				// using flag for taking out of box when dice rolled 6
	
	int flag[4] = {0,0,0 ,0 };
	int flag2[4] = { 0,0,0 ,0 };
	int flag3[4] = { 0,0,0 ,0 };
	int flag4[4] = { 0,0,0 ,0 };
	int occupied=0;
					// using sum for storing rendom number in it and moving on whole board
	int sum[4] = { 0,0,0,0 };
	int sum2[4] = { 0,0,0,0 };
	int sum3[4] = { 0,0,0,0 };
	int sum4[4] = { 0,0,0,0 };
	RenderWindow window(VideoMode(1280, 740), "  FUNNY LUDO -> Team CRUSADERS ", Style::Close  );
	Texture board;
	board.loadFromFile("ludo board.jpg");
	RectangleShape rect;	
	rect.setSize(Vector2f(1260, 780));   
	rect.setTexture(&board);
												// using circle to store gotti in  circle where gotti is a Texture 
	CircleShape circlered[4];										// RED tokken
	CircleShape circleyellow[4];										// YELLOW tokken
	CircleShape circlegreen[4];										// GREEN tokken
	CircleShape circleblue[4];										// BLUE tkeen
	Texture rolling_dice, token_red, token_yellow, token_green, token_blue;
	Sprite roll_dice;
	
	token_red.loadFromFile("red ball.png");						//loading images stored in project folder..
	token_yellow.loadFromFile("yellow ball.png");
	token_green.loadFromFile("green ball.png");
	token_blue.loadFromFile("blue ball.png");
	token_red.setSmooth(true);
	token_yellow.setSmooth(true);
	token_green.setSmooth(true);
	token_blue.setSmooth(true);

	rolling_dice.loadFromFile("dice.png");
	rolling_dice.setSmooth(true);
	roll_dice.setTexture(rolling_dice);
	roll_dice.setScale(0.7,0.7);
	roll_dice.setPosition( Vector2f(570,300) );

	//	label:										// giving board locations of whole board  indexes
	Vector2f array[58] = {/*start from red gotti */Vector2f(520, 625),Vector2f(520,580),Vector2f(520,536),Vector2f(520,489),Vector2f(520,445),/*moving to left board*/Vector2f(444,395),Vector2f(360,395),Vector2f(285,395),Vector2f(215,395),Vector2f(140,395),/*moving left upper */Vector2f(60,395),Vector2f(60,350),Vector2f(60,297)/*start from yellow*/ ,Vector2f(140,297),Vector2f(215,297),Vector2f(285,297),Vector2f(360,297),Vector2f(444,297),Vector2f(520,250),Vector2f(520,205),Vector2f(520,160),Vector2f(520,115),Vector2f(520,70)/*most top*/,Vector2f(520,25),Vector2f(605,25),Vector2f(695,25)/*start from green*/,Vector2f(695,70),Vector2f(695,115),Vector2f(695,160),Vector2f(695,205),Vector2f(695,250),Vector2f(775,297),Vector2f(845,297),Vector2f(920,297),Vector2f(1000,297),Vector2f(1080,297),Vector2f(1145,297),Vector2f(1145,350),Vector2f(1145,395) /*start from blue*/,Vector2f(1070,395),Vector2f(1000,395),Vector2f(920,395),Vector2f(845,395),Vector2f(775,395) /*left-lower moving*/,Vector2f(695,445),Vector2f(695,489),Vector2f(695,489),Vector2f(695,536),Vector2f(695,580),Vector2f(695,625),Vector2f(695,670) /*going inside red cabin*/,Vector2f(605,670),Vector2f(605,625),Vector2f(605,580),Vector2f(605,536),Vector2f(605,489),Vector2f(605,445) };

	Vector2f array2[58] = { /*start from yellow */Vector2f(140,297),Vector2f(215,297),Vector2f(285,297),Vector2f(360,297),Vector2f(444,297),Vector2f(520,250),Vector2f(520,205),Vector2f(520,160),Vector2f(520,115),Vector2f(520,70)/*most top*/,Vector2f(520,25),Vector2f(605,25),Vector2f(695,25)/*start from green*/,Vector2f(695,70),Vector2f(695,115),Vector2f(695,160),Vector2f(695,205),Vector2f(695,250),Vector2f(775,297),Vector2f(845,297),Vector2f(920,297),Vector2f(1000,297),Vector2f(1080,297),Vector2f(1145,297),Vector2f(1145,350),Vector2f(1145,395) /*start from blue*/,Vector2f(1070,395),Vector2f(1000,395),Vector2f(920,395),Vector2f(845,395),Vector2f(775,395) /*left-lower moving*/,Vector2f(695,445),Vector2f(695,489),Vector2f(695,489),Vector2f(695,536),Vector2f(695,580),Vector2f(695,625),Vector2f(695,670),Vector2f(520,670),/*start from red gotti */Vector2f(520, 625),Vector2f(520,580),Vector2f(520,536),Vector2f(520,489),Vector2f(520,445),/*moving to left board*/Vector2f(444,395),Vector2f(360,395),Vector2f(285,395),Vector2f(215,395),Vector2f(140,395),/*moving left upper */Vector2f(60,395),Vector2f(60,350) /*going inside yellow cabin*/,Vector2f(140,350),Vector2f(215,350),Vector2f(250,350),Vector2f(360,350),Vector2f(444,350) };
	
	Vector2f array3[58] = { /*start from green*/Vector2f(695,70),Vector2f(695,115),Vector2f(695,160),Vector2f(695,205),Vector2f(695,250),Vector2f(775,297),Vector2f(845,297),Vector2f(920,297),Vector2f(1000,297),Vector2f(1080,297),Vector2f(1145,297),Vector2f(1145,350),Vector2f(1145,395) /*right moving(blue)*/,Vector2f(1070,395),Vector2f(1000,395),Vector2f(920,395),Vector2f(845,395),Vector2f(775,395) /*left-lower moving*/,Vector2f(695,445),Vector2f(695,489),Vector2f(695,489),Vector2f(695,536),Vector2f(695,580),Vector2f(695,625),Vector2f(695,670),Vector2f(520,670),/*start from red gotti */Vector2f(520, 625),Vector2f(520,580),Vector2f(520,536),Vector2f(520,489),Vector2f(520,445),/*moving to left board*/Vector2f(444,395),Vector2f(360,395),Vector2f(285,395),Vector2f(215,395),Vector2f(140,395),/*moving left upper */Vector2f(60,395),Vector2f(60,350),Vector2f(60,297)/*start from yellow*/ ,Vector2f(140,297),Vector2f(215,297),Vector2f(285,297),Vector2f(360,297),Vector2f(444,297),Vector2f(520,250),Vector2f(520,205),Vector2f(520,160),Vector2f(520,115),Vector2f(520,70)/*most top*/,Vector2f(520,25),Vector2f(605,25)/*going inside green cabin*/,Vector2f(605,70),Vector2f(605,115),Vector2f(605,160),Vector2f(605,205),Vector2f(605,250) };
	
	Vector2f array4[58] = { /*start from blue*/Vector2f(1070,395),Vector2f(1000,395),Vector2f(920,395),Vector2f(845,395),Vector2f(775,395) /*left-lower moving*/,Vector2f(695,445),Vector2f(695,489),Vector2f(695,489),Vector2f(695,536),Vector2f(695,580),Vector2f(695,625),Vector2f(695,670),Vector2f(520,670),/*start from red gotti */Vector2f(520, 625),Vector2f(520,580),Vector2f(520,536),Vector2f(520,489),Vector2f(520,445),/*moving to left board*/Vector2f(444,395),Vector2f(360,395),Vector2f(285,395),Vector2f(215,395),Vector2f(140,395),/*moving left upper */Vector2f(60,395),Vector2f(60,350),Vector2f(60,297)/*start from yellow*/ ,Vector2f(140,297),Vector2f(215,297),Vector2f(285,297),Vector2f(360,297),Vector2f(444,297),Vector2f(520,250),Vector2f(520,205),Vector2f(520,160),Vector2f(520,115),Vector2f(520,70)/*most top*/,Vector2f(520,25),Vector2f(605,25),Vector2f(695,25)/*start from green*/,Vector2f(695,70),Vector2f(695,115),Vector2f(695,160),Vector2f(695,205),Vector2f(695,250),Vector2f(775,297),Vector2f(845,297),Vector2f(920,297),Vector2f(1000,297),Vector2f(1080,297),Vector2f(1145,297),Vector2f(1145,350) /*going inside blue cabin*/,Vector2f(1080,350),Vector2f(1000,350),Vector2f(920,350),Vector2f(845,350),Vector2f(775,350) };
	
	Vector2f storing_to_home[16];
	storing_to_home[0] = { Vector2f(350,489) };		/*for red gotti 1	*/			storing_to_home[4] = { Vector2f(350,65) };		//for yellow gotti 1		
	storing_to_home[1] = { Vector2f(145,489) };		/*for red gotti 2*/				storing_to_home[5] = { Vector2f(145,65) };		//for yellow gotti 2
	storing_to_home[2] = { Vector2f(145,585) };		/*for red gotti 3*/				storing_to_home[6] = { Vector2f(145,160) };		//for yellow gotti 3
	storing_to_home[3] = { Vector2f(350,585) };		/*for red gotti 4*/				storing_to_home[7] = { Vector2f(350,160) };		//for yellow gotti 4
	
	storing_to_home[8] = { Vector2f(1070,65) };		/*for green gotti 1*/			storing_to_home[12] = { Vector2f(1070,489) };		//for blue gotti 1
	storing_to_home[9] = { Vector2f(865 ,65) };		/*for green gotti 2*/			storing_to_home[13] = { Vector2f(865 ,489) };		//for blue gotti 2
	storing_to_home[10] = { Vector2f(865,160) };		/*for green gotti 3*/			storing_to_home[14] = { Vector2f(1070,585) };		//for blue gotti 3
	storing_to_home[11] = { Vector2f(1070,160) };		/*for green gotti 4*/			storing_to_home[15] = { Vector2f(1070,585) };		//for blue gotti 4
	
	board.setSmooth(true);						//making board picture clear then before..	
	for (int i=0;i<4;i++)
	{ 
		circlered[i].setRadius(28);							//setting radious and giving red image in circle to 4 tokkens of red
		circlered[i].setTexture(&token_red);
	}
	for (int i = 0; i < 4; i++)
	{
		circleyellow[i].setRadius(26);										// setting radious and giving red image in circle to 4 tokkens of red
		circleyellow[i].setTexture(&token_yellow);
	}
	for (int i = 0; i < 4; i++)
	{
		circlegreen[i].setRadius(28);										// setting radious and giving red image in circle to 4 tokkens of red
		circlegreen[i].setTexture(&token_green);
	}
	for (int i = 0; i < 4; i++)
	{
		circleblue[i].setRadius(26);										// setting radious and giving red image in circle to 4 tokkens of red
		circleblue[i].setTexture(&token_blue);
	}
	//giving home positions of red			//giving home position of yellow		//giving home position of green			//giving home position of blue
	circlered[0].setPosition(350, 489);		circleyellow[0].setPosition(350, 65 );		circlegreen[0].setPosition(1070, 65 );		circleblue[0].setPosition(1070, 489);
	circlered[1].setPosition(145, 489);		circleyellow[1].setPosition(145, 65 );		circlegreen[1].setPosition(865 , 65 );		circleblue[1].setPosition(865 , 489);
	circlered[2].setPosition(145, 585);		circleyellow[2].setPosition(145, 160);		circlegreen[2].setPosition(865 , 160);		circleblue[2].setPosition(865 , 585);
	circlered[3].setPosition(350, 585);		circleyellow[3].setPosition(350, 160);		circlegreen[3].setPosition(1070, 160);		circleblue[3].setPosition(1070, 585);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))									//any event which occur in "event" stores in it.
		{
			if (event.type == Event::Closed)							//pressing |x| or alt+f4 . it closes window
				window.close();

			if (event.type == Event::MouseButtonPressed)
			{
				// ||________________________________________________START OF RED TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||	

				if (Mouse::isButtonPressed(Mouse::Left))										//left button for red tokken movement
				{
					cout << " \t RED MOVING \n";
					cout << "\t left click is pressed.. player1 is moving..\n " << endl;
					roll = rand() % 6 + 1;														// generating random number of red
					cout << " random number is : " << roll << endl;

					if (circlered[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{
						//flag to move gottti out of home and move in track
						if (flag[0] == 0)
						{
							if (roll == 6)
							{
								circlered[0].setPosition(array[0]);			//when its's out. giving its outing position index of array
								++flag[0];
								break;
							}
						}
						if (flag[0] == 1)
						{
							occupied = 1;
							//using sum to store sum random numbers 
							sum[0] = sum[0] + roll;
							circlered[0].setPosition(array[0 + sum[0]]);		// sum will move the indexes whose random number is generating.

						}


					}
					else if (circlered[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{
						//next gotti of red conditions.. flag to move out 2nd gotti... changes are : flag and sum is new type 
						if (flag[1] == 0)
						{
							if (roll == 6)
							{
								circlered[1].setPosition(array[0]);
								++flag[1];

								break;
							}
						}
						if (flag[1] == 1)
						{
							occupied = 2;
							sum[1] = sum[1] + roll;
							circlered[1].setPosition(array[0 + sum[1]]);
						}


					}
					else if (circlered[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{
						//next gotti of red conditions.. flag to move out 2nd gotti... changes are : flag and sum is new type 
						if (flag[2] == 0)
						{
							if (roll == 6)
							{
								circlered[2].setPosition(array[0]);
								++flag[2];

								break;
							}
						}
						if (flag[2] == 1)
						{
							occupied = 3;
							sum[2] = sum[2] + roll;
							circlered[2].setPosition(array[0 + sum[2]]);
						}

						break;
					}
					else if (circlered[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{
						//next gotti of red conditions.. flag to move out 2nd gotti... changes are : flag and sum is new type 
						if (flag[3] == 0)
						{
							if (roll == 6)
							{
								circlered[3].setPosition(array[0]);
								++flag[3];

								break;
							}
						}
						if (flag[3] == 1)
						{
							occupied = 4;
							sum[3] = sum[3] + roll;
							circlered[3].setPosition(array[0 + sum[3]]);
						}

						/*						for (int i = 0; i < 4; i++)
												{
													flag[i] = { 0 };
												}*/
					}

					for (int i = 0; i < 4; i++)
					{
//red gottti sending back yellow gotti
						if (circlered[i].getGlobalBounds().intersects(circleyellow[i].getGlobalBounds()) )
						{

			
							circleyellow[i].setPosition(storing_to_home[ 4]);
							sum2[i] = 0;
								flag2[i] = 0;
								//							goto label;							
						}
					
						else if (circlered[i].getGlobalBounds().intersects(circleyellow[i + 1].getGlobalBounds()) )
						{
							circleyellow[i+1].setPosition(storing_to_home[5]);
							sum2[i+1] = 0;
							flag2[i+1] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circleyellow[i + 2].getGlobalBounds()) )
						{
							circleyellow[i+2].setPosition(storing_to_home[ 6]);
							sum2[i + 2] = 0;
							flag2[i + 2] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circleyellow[i + 3].getGlobalBounds()))
						{
							circleyellow[i+3].setPosition(storing_to_home[ 7]);
							sum2[i + 3] = 0;
							flag2[i + 3] = 0;
						}

//red gotti sending back green gotti

						else if (circlered[i].getGlobalBounds().intersects(circlegreen[i].getGlobalBounds()))
						{

							//sum[i] = 0;
							//flag[i] = 0;
							circlegreen[i].setPosition(storing_to_home[8]);
							sum3[i] = 0;
								flag3[i] = 0;
								//							goto label;							
						}
						else if (circlered[i].getGlobalBounds().intersects(circlegreen[i + 1].getGlobalBounds()))
						{
							circlegreen[i + 1].setPosition(storing_to_home[9]);
							sum3[i + 1] = 0;
							flag3[i + 1] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circlegreen[i + 2].getGlobalBounds()))
						{
							circlegreen[i + 2].setPosition(storing_to_home[10]);
							sum3[i + 2] = 0;
							flag3[i + 2] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circlegreen[i + 3].getGlobalBounds()))
						{
							circlegreen[i+3].setPosition(storing_to_home[11]);
							sum3[i + 3] = 0;
							flag3[i + 3] = 0;
						}


//red gotti sending back blue gotti
						else if (circlered[i].getGlobalBounds().intersects(circleblue[i].getGlobalBounds()))
						{

							//sum[i] = 0;
							//flag[i] = 0;
							circleblue[i].setPosition(storing_to_home[12]);
							sum4[i] = 0;
								flag4[i] = 0;
								//							goto label;							
						}
						else if (circlered[i].getGlobalBounds().intersects(circleblue[i + 1].getGlobalBounds()))
						{
							circleblue[i + 1].setPosition(storing_to_home[13]);
							sum4[i + 1] = 0;
							flag4[i + 1] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circleblue[i + 2].getGlobalBounds()))
						{
							circleblue[i + 2].setPosition(storing_to_home[14]);
							sum4[i + 2] = 0;
							flag4[i + 2] = 0;
						}
						else if (circlered[i].getGlobalBounds().intersects(circleblue[i + 3].getGlobalBounds()))
						{
							circleblue[i + 3].setPosition(storing_to_home[15]);
							sum4[i + 3] = 0;
							flag4[i + 3] = 0;
						}

					}

				}
				// ||________________________________________________END OF RED TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||		

										//same conditions as of red.. difference is mouse click is right and flag and sum are 5-8.......
				// ||________________________________________________START OF YELLOW TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||		
				else if (Mouse::isButtonPressed(Mouse::Right))
				{
					cout << " \t YELLOW MOVING \n";
					cout << "\t right click is pressed .. player2 is moving..\n " << endl;
					roll = rand() % 6 + 1;
					cout << " random number is : " << roll << endl;

					if (circleyellow[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag2[0] == 0)
						{
							if (roll == 6)
							{
								circleyellow[0].setPosition(array2[0]);
								++flag2[0];

								break;
							}
						}
						if (flag2[0] == 1)
						{
							occupied = 5;
							sum2[0] = sum2[0] + roll;
							circleyellow[0].setPosition(array2[0 + sum2[0]]);
						}


					}
					else if (circleyellow[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{


						if (flag2[1] == 0)
						{
							if (roll == 6)
							{
								circleyellow[1].setPosition(array2[0]);
								++flag2[1];

								break;
							}
						}
						if (flag2[1] == 1)
						{
							occupied = 6;
							sum2[1] = sum2[1] + roll;
							circleyellow[1].setPosition(array2[0 + sum2[1]]);
						}


					}
					else if (circleyellow[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag2[2] == 0)
						{
							if (roll == 6)
							{
								circleyellow[2].setPosition(array2[0]);
								++flag2[2];

								break;
							}
						}
						if (flag2[2] == 1)
						{
							occupied = 7;
							sum2[2] = sum2[2] + roll;
							circleyellow[2].setPosition(array2[0 + sum2[2]]);
						}

						break;
					}
					else if (circleyellow[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag2[3] == 0 /*|| flag4 == 0*/)
						{
							if (roll == 6)
							{
								circleyellow[3].setPosition(array2[0]);
								++flag2[3];

								break;
							}
						}
						if (flag2[3] == 1)
						{
							occupied = 8;
							sum2[3] = sum2[3] + roll;
							circleyellow[3].setPosition(array2[0 + sum2[3]]);
						}

					}
					for (int i = 0; i < 4; i++)
					{
	//yellow gottti sending back red gotti
						if (circleyellow[i].getGlobalBounds().intersects(circlered[i].getGlobalBounds()))
						{


							circlered[i].setPosition(storing_to_home[0]);
							sum[i] = 0;
							flag[i] = 0;
							//							goto label;							
						}

						else if (circleyellow[i].getGlobalBounds().intersects(circlered[i + 1].getGlobalBounds()))
						{
							circlered[i + 1].setPosition(storing_to_home[1]);
							sum[i + 1] = 0;
							flag[i + 1] = 0;
						}
						else if (circleyellow[i].getGlobalBounds().intersects(circlered[i + 2].getGlobalBounds()))
						{
							circlered[i + 2].setPosition(storing_to_home[2]);
							sum[i + 2] = 0;
							flag[i + 2] = 0;
						}
						else if (circleyellow[i].getGlobalBounds().intersects(circlered[i + 3].getGlobalBounds()))
						{
							circlered[i + 3].setPosition(storing_to_home[3]);
							sum[i + 3] = 0;
							flag[i + 3] = 0;
						}


//yellow gotti sending back green gotti

						else if (circleyellow[i].getGlobalBounds().intersects(circlegreen[i].getGlobalBounds()))
						{

							//sum[i] = 0;
							//flag[i] = 0;
							circlegreen[i].setPosition(storing_to_home[8]);
							sum3[i] = 0;
								flag3[i] = 0;
								//							goto label;							
						}
						else if (circleyellow[i].getGlobalBounds().intersects(circlegreen[i + 1].getGlobalBounds()))
						{
							circlegreen[i + 1].setPosition(storing_to_home[9]);
							sum3[i + 1] = 0;
							flag3[i + 1] = 0;
						}
						else if (circleyellow[i].getGlobalBounds().intersects(circlegreen[i + 2].getGlobalBounds()))
						{
							circlegreen[i + 2].setPosition(storing_to_home[10]);
							sum3[i + 2] = 0;
							flag3[i + 2] = 0;
						}
						else if (circleyellow[i].getGlobalBounds().intersects(circlegreen[i + 3].getGlobalBounds()))
						{
							circlegreen[i + 3].setPosition(storing_to_home[11]);
							sum3[i + 3] = 0;
							flag3[i + 3] = 0;
						}


//yellow gotti sending back blue gotti
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i].getGlobalBounds()))
						{

							//sum[i] = 0;
							//flag[i] = 0;
							circleblue[i].setPosition(storing_to_home[12]);
							sum4[i] = 0;
							flag4[i] = 0;
							//							goto label;							
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 1].getGlobalBounds()))
						{
							circleblue[i + 1].setPosition(storing_to_home[13]);
							sum4[i + 1] = 0;
							flag4[i + 1] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 2].getGlobalBounds()))
						{
							circleblue[i + 2].setPosition(storing_to_home[14]);
							sum4[i + 2] = 0;
							flag4[i + 2] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 3].getGlobalBounds()))
						{
							circleblue[i + 3].setPosition(storing_to_home[15]);
							sum4[i + 3] = 0;
							flag4[i + 3] = 0;
						}


					}

				}
// ||________________________________________________END OF YELLOW TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||			
// ||________________________________________________START OF GREEN TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||		
				else if (Mouse::isButtonPressed(Mouse::XButton1))
				{
					cout << " \t GREEN MOVING \n";
					cout << "\t right click is pressed .. player2 is moving..\n " << endl;
					roll = rand() % 6 + 1;
					cout << " random number is : " << roll << endl;

					if (circlegreen[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{


						if (flag3[0] == 0)
						{
							if (roll == 6)
							{
								circlegreen[0].setPosition(array3[0]);
								++flag3[0];

								break;
							}
						}
						if (flag3[0] == 1)
						{
							occupied = 9;
							sum3[0] = sum3[0] + roll;
							circlegreen[0].setPosition(array3[0 + sum3[0]]);
						}


					}
					else if (circlegreen[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{


						if (flag2[1] == 0)
						{
							if (roll == 6)
							{
								circlegreen[1].setPosition(array3[0]);
								++flag2[1];

								break;
							}
						}
						if (flag2[1] == 1)
						{
							occupied = 10;
							sum2[1] = sum2[1] + roll;
							circlegreen[1].setPosition(array3[0 + sum2[1]]);
						}


					}
					else if (circlegreen[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag2[2] == 0)
						{
							if (roll == 6)
							{
								circlegreen[2].setPosition(array3[0]);
								++flag2[2];

								break;
							}
						}
						if (flag2[2] == 1)
						{
							occupied = 11;
							sum2[2] = sum2[2] + roll;
							circlegreen[2].setPosition(array3[0 + sum2[2]]);
						}

						break;
					}
					else if (circlegreen[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag3[3] == 0 /*|| flag4 == 0*/)
						{
							if (roll == 6)
							{
								circlegreen[3].setPosition(array3[0]);
								++flag3[3];

								break;
							}
						}
						if (flag3[3] == 1)
						{
							occupied = 12;
							sum3[3] = sum3[3] + roll;
							circlegreen[3].setPosition(array3[0 + sum3[3]]);
						}

						/*					for (int i = 0; i < 4; i++)
											{
												flag3[i] = { 0 };
											}*/
					}

					for (int i = 0; i < 4; i++)
					{
//yellow killing red
						if (circlegreen[i].getGlobalBounds().intersects(circlered[i].getGlobalBounds()))
						{


							circlered[i].setPosition(storing_to_home[0]);
							sum[i] = 0;
							flag[i] = 0;
							//							goto label;							
						}

						else if (circlegreen[i].getGlobalBounds().intersects(circlered[i + 1].getGlobalBounds()))
						{
							circlered[i + 1].setPosition(storing_to_home[1]);
							sum[i + 1] = 0;
							flag[i + 1] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circlered[i + 2].getGlobalBounds()))
						{
							circlered[i + 2].setPosition(storing_to_home[2]);
							sum[i + 2] = 0;
							flag[i + 2] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circlered[i + 3].getGlobalBounds()))
						{
							circlered[i + 3].setPosition(storing_to_home[3]);
							sum[i + 3] = 0;
							flag[i + 3] = 0;
						}




//green sending back yellow
						else if (circlegreen[i].getGlobalBounds().intersects(circleyellow[i].getGlobalBounds()))
						{


							circleyellow[i].setPosition(storing_to_home[4]);
							sum2[i] = 0;
							flag2[i] = 0;
							//							goto label;							
						}

						else if (circlegreen[i].getGlobalBounds().intersects(circleyellow[i + 1].getGlobalBounds()))
						{
							circleyellow[i + 1].setPosition(storing_to_home[5]);
							sum2[i + 1] = 0;
							flag2[i + 1] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleyellow[i + 2].getGlobalBounds()))
						{
							circleyellow[i + 2].setPosition(storing_to_home[6]);
							sum2[i + 2] = 0;
							flag2[i + 2] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleyellow[i + 3].getGlobalBounds()))
						{
							circleyellow[i + 3].setPosition(storing_to_home[7]);
							sum2[i + 3] = 0;
							flag2[i + 3] = 0;
						}



//green killing blue
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i].getGlobalBounds()))
						{

							//sum[i] = 0;
							//flag[i] = 0;
							circleblue[i].setPosition(storing_to_home[12]);
							sum4[i] = 0;
							flag4[i] = 0;
							//							goto label;							
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 1].getGlobalBounds()))
						{
							circleblue[i + 1].setPosition(storing_to_home[13]);
							sum4[i + 1] = 0;
							flag4[i + 1] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 2].getGlobalBounds()))
						{
							circleblue[i + 2].setPosition(storing_to_home[14]);
							sum4[i + 2] = 0;
							flag4[i + 2] = 0;
						}
						else if (circlegreen[i].getGlobalBounds().intersects(circleblue[i + 3].getGlobalBounds()))
						{
							circleblue[i + 3].setPosition(storing_to_home[15]);
							sum4[i + 3] = 0;
							flag4[i + 3] = 0;
						}
					}


				}
// ||________________________________________________END OF GREEN TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||			
// ||________________________________________________START OF BLUE TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||		
				else if (Mouse::isButtonPressed(Mouse::XButton2))
				{
					cout << " \t BLUE MOVING \n";
					cout << "\t right click is pressed .. player2 is moving..\n " << endl;
					roll = rand() % 6 + 1;
					cout << " random number is : " << roll << endl;

					if (circleblue[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{


						if (flag4[0] == 0)
						{
							if (roll == 6)
							{
								circleblue[0].setPosition(array4[0]);
								++flag4[0];

								break;
							}
						}
						if (flag4[0] == 1)
						{
							occupied = 13;
							sum4[0] = sum4[0] + roll;
							circleblue[0].setPosition(array4[0 + sum4[0]]);
						}


					}
					else if (circleblue[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{


						if (flag4[1] == 0)
						{
							if (roll == 6)
							{
								circleblue[1].setPosition(array4[0]);
								++flag4[1];

								break;
							}
						}
						if (flag4[1] == 1)
						{
							occupied = 14;
							sum4[1] = sum4[1] + roll;
							circleblue[1].setPosition(array4[0 + sum4[1]]);
						}


					}
					else if (circleblue[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag4[2] == 0)
						{
							if (roll == 6)
							{
								circleblue[2].setPosition(array4[0]);
								++flag4[2];

								break;
							}
						}
						if (flag4[2] == 1)
						{
							occupied = 15;
							sum4[2] = sum4[2] + roll;
							circleblue[2].setPosition(array4[0 + sum4[2]]);
						}

						break;
					}
					else if (circleblue[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
					{

						if (flag4[3] == 0 /*|| flag4 == 0*/)
						{
							if (roll == 6)
							{
								circleblue[3].setPosition(array4[0]);
								++flag4[3];

								break;
							}
						}
						if (flag4[3] == 1)
						{
							occupied = 16;
							sum4[3] = sum4[3] + roll;
							circleblue[3].setPosition(array4[0 + sum4[3]]);
						}

					}
					for (int i = 0; i < 4; i++)
					{
//blue killing red
					if (circleblue[i].getGlobalBounds().intersects(circlered[i].getGlobalBounds()))
					{

						circlered[i].setPosition(storing_to_home[0]);
						sum[i] = 0;
						flag[i] = 0;
						//							goto label;							
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlered[i + 1].getGlobalBounds()))
					{
						circlered[i + 1].setPosition(storing_to_home[1]);
						sum[i + 1] = 0;
						flag[i + 1] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlered[i + 2].getGlobalBounds()))
					{
						circlered[i + 2].setPosition(storing_to_home[2]);
						sum[i + 2] = 0;
						flag[i + 2] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlered[i + 3].getGlobalBounds()))
					{
						circlered[i + 3].setPosition(storing_to_home[3]);
						sum[i + 3] = 0;
						flag[i + 3] = 0;
					}


//blue killing yellow
					else if (circleblue[i].getGlobalBounds().intersects(circleyellow[i].getGlobalBounds()))
					{


						circleyellow[i].setPosition(storing_to_home[4]);
						sum2[i] = 0;
						flag2[i] = 0;
						//							goto label;							
					}

					else if (circleblue[i].getGlobalBounds().intersects(circleyellow[i + 1].getGlobalBounds()))
					{
						circleyellow[i + 1].setPosition(storing_to_home[5]);
						sum2[i + 1] = 0;
						flag2[i + 1] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circleyellow[i + 2].getGlobalBounds()))
					{
						circleyellow[i + 2].setPosition(storing_to_home[6]);
						sum2[i + 2] = 0;
						flag2[i + 2] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circleyellow[i + 3].getGlobalBounds()))
					{
						circleyellow[i + 3].setPosition(storing_to_home[7]);
						sum2[i + 3] = 0;
						flag2[i + 3] = 0;
					}




//blue killing green
					else if (circleblue[i].getGlobalBounds().intersects(circlegreen[i].getGlobalBounds()))
					{

						//sum[i] = 0;
						//flag[i] = 0;
						circlegreen[i].setPosition(storing_to_home[8]);
						sum3[i] = 0;
						flag3[i] = 0;
						//							goto label;							
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlegreen[i + 1].getGlobalBounds()))
					{
						circlegreen[i + 1].setPosition(storing_to_home[9]);
						sum3[i + 1] = 0;
						flag3[i + 1] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlegreen[i + 2].getGlobalBounds()))
					{
						circlegreen[i + 2].setPosition(storing_to_home[10]);
						sum3[i + 2] = 0;
						flag3[i + 2] = 0;
					}
					else if (circleblue[i].getGlobalBounds().intersects(circlegreen[i + 3].getGlobalBounds()))
					{
						circlegreen[i + 3].setPosition(storing_to_home[11]);
						sum3[i + 3] = 0;
						flag3[i + 3] = 0;
					}
					}



				}

// ||________________________________________________END OF BLUE TOKKEN MMOVEMENT CONDITIONS___________________________________________________________________________	|||			


			}
		
	
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------		
				//peetche wali gotti           aagw wali     gotti ki boundaries ko lage...     
				//for (int i = 0; i < 4; i++)
				//{
				//	if (Mouse::isButtonPressed(Mouse::Left))
				//	{
				//		if (circlered[i].getGlobalBounds().intersects(circleyellow[i].getGlobalBounds()))
				//		{

				//			sum[i] = 0;							
				//			flag[i] = 0;						
				//			circleyellow[i].setPosition(storing_to_home[i+4]);
				//			sum[i] = 0;
				//			flag[i] = 1;
				//			//							goto label;							
				//		}
				//	}
					//else if (Mouse::isButtonPressed(Mouse::Right))
					//{
					//	if (circleyellow[i].getGlobalBounds().intersects(circlered[i].getGlobalBounds()))
					//	{
					//		sum2[i] = 0;
					//		flag2[i] = 0;
					//		circlered[i].setPosition(storing_to_home[i]);
					//		sum2[i] = 0;
					//		flag2[i] = 1;
					//		//							goto label;

					//	}

					//}
				
					//------------------------------------------------------------------------------------------------------------------------------------------------
			window.clear();	
			window.draw(rect);

			for (int i = 0; i < 4; i++)
			{
				window.draw(circlered[i]);
			}
			for (int i = 0; i < 4; i++)
			{
				window.draw(circleyellow[i]);
			}
			for (int i = 0; i < 4; i++)
			{
				window.draw(circlegreen[i]);
			}
			for (int i = 0; i < 4; i++)
			{
				window.draw(circleblue[i]);
			}
			window.draw(roll_dice);
			window.display();
		}
	}
}
void loading()
{
	for (int shaska = 0; shaska <= 100; shaska++)
	{
		cout << "\n\n\n\n\n\n\n\n\n \t\t\t\t\t\tloading ..." << shaska << endl;
		Sleep(30);
		system("CLS");
	}
	cout << "\n \t \t \t loading completed.";
	Sleep(2000);
}

void instructions()
{
	int selection1;
	cout << " \n\n\t \t\t WELCOME TO FUNNY LUDO 2.0 ";
	cout << "\n\t\t    _____________________________________________";
	cout << "\n\t\t     |Here are some instructions you must know :|     ";
	cout << "\n\t\t       |                                      |      ";
	cout << "\n\t\t         |                                  |      ";
	cout << "\n\t\t           |                              |      ";
	cout << "\n\t\t             |                          |      ";
	cout << "\n\t\t               |______________________|      ";
	cout << "\n\t\t                    |            |      ";
	cout << "\n\t\t                    |            |      ";
	cout << "\n\t\t                     |          |      ";
	cout << "\n\t\t                       |      |      ";
	cout << "\n\t\t                         |  |      ";
	cout << "\n\t\t                          VV     ";
	cout << "\n\t\t        NO need to give instructions you already know how to play ludo    ";
	cout << "\n\t\t                just difference is rules are mine    ";
	cout << "\n \t\t               included players are :\n\t 1. player1 (RED TOKKEN)\n\t 2. player2 (YELLOW TOKKEN)\n\t 3. player3 (GREEN TOKKEN)\n\t 4. player4 (BLUE TOKKEN) ";

	cout << " \n \n\t Enter what do  you want to choose : \n 1. To display board \n 2. To exit." << endl;
	cin >> selection1;
	if (selection1 == 1)
	{
		ludo_board();

	}
	else if (selection1 == 2)
	{
		system("cls");

		cout << "\n\n\n\t\t you just successfully wasted your time -_-  \n\n";
		cout << " \t\t Team CRUSADERS -> thanks for visiting..";
	}

}

void highscores()
{
	int selection3;
	string score_file;
	ifstream file;
	file.open("playerscore.txt");

	while (!file.eof())
	{
		getline(file, score_file);
		cout << score_file;
		cout << endl;
	}
	cout << " \n \n\t Enter what do  you want to choose : \n 1. To display board\n 2. To instructions \n 3. To exit." << endl;
	cin >> selection3;
	
	if (selection3 == 1)
	{
		ludo_board();

	}

	else if (selection3 == 2)
	{
		instructions();
	}

	else if (selection3 == 3)
	{
		system("cls");

		cout << "\n\n\n\t\t you just successfully wasted your time -_-  \n\n";
		cout << " \t\t Team CRUSADERS -> thanks for visiting..";
	}
}

int main()
{
	loading();
	
	system("CLS");
	int selection2;
	cout << endl;
	cout << " \t \t -------------------------" << endl;
	cout << " \t \t |STARTING FUNNY LUDO 2.0| " <<endl;
	cout << " \t \t ------------------------- \n" << endl;
	cout << "\t This game is made by: \n\t 1. Arham Irfan \n\t 2. Umbreen Kiran\n" << endl;
	cout << "    Team CRUSADERS -> ENJOY AND HAVE FUN ! \n\n";
	cout << "  Choose one of the following : Enter \n 1. To see instructions \n 2. To start game \n 3. To show highscores \n 4. To exit \n";
	cout << " Your choice is :";
	cin >> selection2;

	if (selection2 ==1)
	{
		system("cls");
		instructions();
	}
	else if (selection2 ==2)
	{
		ludo_board();
		
	}
	else if (selection2 == 3)
	{
		system("cls");
		highscores();

	}
	else if (selection2 == 4)
	{
		system("cls");

		cout << "\n\n\n\t\t you just successfully wasted your time -_-  \n\n";
		cout << " \t\t Team CRUSADERS -> thanks for visiting..";
	}
	system("pause>0");
}