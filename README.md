git clone https://github.com/puHoraira/DualGameDemo

cd DualGameDemo

gcc main.c sdlevent.c sdlrender.c sdlshape.c starter.c credit.c copyofMain.c chess.c  -lSDL2 -lSDL2_image -lSDL2_ttf -o dualgame

./dualgame
