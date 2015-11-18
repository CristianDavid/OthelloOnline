#include "boardhandler.h"

BoardHandler::BoardHandler() {
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         board[i][j] = NONE;
      }
   }
}
