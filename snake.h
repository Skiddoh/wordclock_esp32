/**
 * @file snake.h
 * @author techniccontroller (mail[at]techniccontroller.com)
 * @brief Class definition of Snake game
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * main code from https://elektro.turanis.de/html/prj099/index.html
 * 
 */
#ifndef snake_h
#define snake_h

#include <Arduino.h>
#include "ledmatrix.h"
#include "udplogger.h"

#define DEBOUNCE_TIME 300   // in ms

#define X_MAX 11
#define Y_MAX 11

#define GAME_DELAY 400      // in ms

#define LED_TYPE_SNAKE 1
#define LED_TYPE_OFF   2
#define LED_TYPE_FOOD  3
#define LED_TYPE_BLOOD 4

#define DIRECTION_NONE  0
#define DIRECTION_UP    1
#define DIRECTION_DOWN  2
#define DIRECTION_LEFT  3
#define DIRECTION_RIGHT 4

#define GAME_STATE_RUNNING 1
#define GAME_STATE_END     2
#define GAME_STATE_INIT    3

#define MAX_TAIL_LENGTH X_MAX * Y_MAX
#define MIN_TAIL_LENGTH 3

struct Coords {
  int x;
  int y;
};


class Snake{
    public:
        Snake();
        Snake(LEDMatrix *myledmatrix, UDPLogger *mylogger);
        void loopCycle();
        void initGame();
        void ctrlUp();
        void ctrlDown();
        void ctrlLeft();
        void ctrlRight();
        
    private:
        LEDMatrix *ledmatrix;
        UDPLogger logger;
        uint8_t incomingByte = 0;
        uint8_t userDirection;
        uint8_t gameState;
        Coords head;
        Coords tail[MAX_TAIL_LENGTH];
        Coords food;
        unsigned long lastDrawUpdate = 0;
        unsigned long lastButtonClick;
        unsigned int wormLength = 0;

        void resetLEDs();
        void updateGame();
        void endGame();
        void updateTail();
        void updateFood();
        bool isCollision();
        void toggleLed(uint8_t x, uint8_t y, uint8_t type);

};

#endif