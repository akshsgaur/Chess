CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = chess
OBJECTS = cell.o board.o main.o textDisplay.o piece.o specialPiece.o king.o queen.o bishop.o knight.o rook.o pawn.o graphicalDisplay.o window.o player.o humanPlayer.o computerPlayer.o chess.o levelOne.o levelTwo.o levelThree.o levelFour.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm cell.o board.o main.o textDisplay.o piece.o specialPiece.o king.o queen.o bishop.o knight.o rook.o pawn.o graphicalDisplay.o window.o player.o humanPlayer.o computerPlayer.o chess.o levelOne.o levelTwo.o levelThree.o levelFour.o ${EXEC} cell.d board.d main.d textDisplay.d piece.d specialPiece.d king.d queen.d bishop.d knight.d rook.d pawn.d graphicalDisplay.d window.d player.d humanPlayer.d computerPlayer.d chess.d levelOne.d levelTwo.d levelThree.d levelFour.d
