#include <cstdlib>
#include <iostream>
#include <climits>
#include <ctime>
#include <string>
using namespace std;
int nbAlumetteOrdiExpert(int nbRestant){
	for(int i = 1; i <= 3; ++i){
		if((nbRestant-i) % 4==1){
			return i;
		}
	}
	return 1+rand() % 3;
}
int nbAlumetteOrdiEasy(){
	return (rand()%3)+1;
}

int jouer(string nom){
	int nb = -1;
	while(nb < 0 || nb > 3){
		cout << "C'est au tour de "<< nom<< ". Veuillez saisir un chiffre en 1 et 3" << endl;
		cin >> nb;
	}
	return nb;
}
int ordiJouer(int difficulty,int nbAlumette){
	int nb;
	cout << "C'est au tour de l'ordinateur." << endl;
	switch(difficulty){
		case 0:
			nb = nbAlumetteOrdiEasy();
			break;
		case 1:
			nb = nbAlumetteOrdiExpert(nbAlumette);
			break;
	}
	cout << "L'ordinateur prend " << nb << " alumettes." << endl;
	return nb;
}

int main(int argc, char **argv)
{
	std::srand(std::time(nullptr));
	int turn = 0;
	int player = rand() % 2;
	int nbAlumette = 30;
	int nb = 0;
	int difficulty = -1;
	int jcj = -1;
	while(jcj<0 ||jcj > 1){
		cout << "Mode JCJ ? 0 = Non, 1 = Oui" << endl;
		cin >> jcj;
	}
	if(jcj == 0){
		while(difficulty<0 ||difficulty > 1){
			cout << "Choisissez une difficulté (0 = facile, 1 = expert)" << endl;
			cin >> difficulty;
		}
	}

	string adversaire = jcj == 1 ? "Joueur 2" : "L'ordinateur";
	cout << "Le jeu démarre. Il y a " << nbAlumette << endl;
	while(true){
		if(turn % 2 == player){
			nb = jouer("Joueur 1");
		}
		else {
			if(jcj == 0){
				nb = ordiJouer(difficulty, nbAlumette);
			}
			else {
				nb = jouer("Joueur 2");
			}
		}
		nbAlumette -= nb;
		cout << "Il reste " << nbAlumette << " alumettes." << endl;
		if(nbAlumette <= 0){
			if(turn % 2 == player){
				cout << "Le Joueur 1 à pardu" << endl;
			}
			else {
				cout << adversaire << " à perdu" << endl;
			}
			break;
		}
		++turn;
	}
}
