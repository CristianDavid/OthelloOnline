#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

enum Fichas {
   NONE = 0,
   BLACK,
   WHITE
};

class BoardHandler {
public:
   BoardHandler();
private:
   char board[8][8];
};

#endif // BOARDHANDLER_H
