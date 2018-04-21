struct game
{
	int a[4][4];
	char name[100];
	int n;
	int counter;
	//int score;
};
void createGame(int x, int y);
void reloadSavedGame();
void save(game* user);
int playLeft(game* board);
int playRight(game* board);
int playUp(game* board);
int playDown(game* board);
void showLeaderBoard();
int getPrevFibo(int value);
int getNextFibo(int value);
void play(game* board);
void reload();
void writeIntoFile(game* user);
void pushing(game* board);
void poping(game* board);
void clearing();
void preview(game* board);