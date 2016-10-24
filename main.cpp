#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string> 
#include <sstream>
#include <vector>
#include <windows.h>

#include "irr/irrlicht.h"
#include "Constante.h"
#include "trackballcamera.h"

using namespace std;	
using namespace irr;
using namespace scene;
using namespace io;
using namespace core;
using namespace gui; 
using std::vector;

IrrlichtDevice *device = 0;
s32 cnt = 0;
IGUIListBox* listbox = 0;
bool quit = 1, Bool_Option = 0,Bool_Mouvement = 0, Bool_Valider_Remplissage_Aléatoire = 0, Bool_Valider_Nombres_Etapes =0, Bool_Edit_Box_CasesConcernes = 0, Bool_Quitter_Options = 0, Bool_Quitter_Attention = 0, Bool_Quitter_Attention2 = 0, Bool_Affichage_cube = 0, Bool_Algo = 0,  Bool_Lancement_Algo = 0, Bool_Choix_Cases = 0, Bool_Choix_Fin = 0, Bool_Affichage_Choix = 0, Bool_Choix_Cases2 = 0, Bool_Clique_Souris = 0, Bool_Clique_Souris2 = 0,Bool_Remplissage_Case = 0, Bool_Camera_position = 0, Bool_position = 0,Bool_Remise_a_Zero = 0, Bool_Taille_Grille = 0, Bool_Choix_Taille_Grille = 0, Bool_Fin_Taille_Grille = 0, Bool_Conditions = 0, Bool_Valider_Condition = 0, Bool_Condition_Quitte = 0, Bool_Invaiance = 0,Bool_Invaiance_création_grille=0, bool_création_fenetre_invariance = 0, bool_quitter_fenetre_invariance = 0, bool_création_fenetre_invariance_trouvé = 0; 

int TailleGrille = 25, Taille_Grille_ancienne = 0;

 // Souris X/Y
struct mouseData
{
   int X;
   int Y;
};
struct mouseData mouse;

//Gestion des évènements
class MyEventReceiver : public IEventReceiver
{
public:

	virtual bool OnEvent(const SEvent& event)
	{

			if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
            {
				if (Bool_Choix_Cases == 1)
				{
                switch(event.MouseInput.Event)
				{
					case EMIE_MOUSE_MOVED:
						Bool_Mouvement = 1;
						mouse.X = event.MouseInput.X;
						mouse.Y = event.MouseInput.Y;
					break;

					case EMIE_LMOUSE_PRESSED_DOWN:
                    //EMIE_LMOUSE_PRESSED_DOWN
					mouse.X = event.MouseInput.X;
					mouse.Y = event.MouseInput.Y;

					Bool_Clique_Souris = 1;
				
                    break;
						case  EMIE_RMOUSE_PRESSED_DOWN:
							Bool_Choix_Cases = 0;
							Bool_Choix_Fin = 1;
							Bool_Affichage_cube = 1;
					break;

					break;
                }
				}
				if (Bool_Choix_Cases2 == 1)
				{
					switch(event.MouseInput.Event)
					{
						case EMIE_MOUSE_MOVED:
						Bool_Mouvement = 1;
						mouse.X = event.MouseInput.X;
						mouse.Y = event.MouseInput.Y;
					break;

						case EMIE_LMOUSE_PRESSED_DOWN:
                    //EMIE_LMOUSE_PRESSED_DOWN
					mouse.X = event.MouseInput.X;
					mouse.Y = event.MouseInput.Y;

					Bool_Clique_Souris2 = 1;
				
                    break;
						case  EMIE_RMOUSE_PRESSED_DOWN:
							Bool_Camera_position = 1;
							Bool_position = 1;
							Bool_Choix_Cases2 = 0;
							Bool_Choix_Cases = 1;
						break;
					}
				}
		}
		

		
		if (event.EventType == EET_GUI_EVENT)
		{
			s32 id = event.GUIEvent.Caller->getID();
			//IGUIEnvironment* env = device->getGUIEnvironment();

            switch(event.GUIEvent.EventType)
            {
				case EGET_BUTTON_CLICKED:
					if (id == 101)
					{
						quit = 0;
					}
					if (id == 102)
					{
						Bool_Algo = 1;
						Bool_Lancement_Algo = 1;
					}
					if (id == 103)
					{
						Bool_Option = 1;
					}
					if (id == 104)
					{
						Bool_Lancement_Algo = 0;
						Bool_Invaiance = 0;
					}
					if (id == 105)
					{
						Bool_Invaiance_création_grille = 1;
					}
					if (id == 106)
					{
						Bool_Valider_Remplissage_Aléatoire = 1;
					}
					if (id == 107)
					{
						Bool_Valider_Nombres_Etapes = 1;
					}
					if (id == 108)
					{
						Bool_Quitter_Options = 1;
					}
					if (id == 109)
					{
						Bool_Remise_a_Zero = 1;
					}
					if (id == 110)
					{
						Bool_Taille_Grille = 1;
					}
					if (id == 111)
					{
						Bool_Conditions = 1;
					}
					if (id == 120)
					{
						Bool_Quitter_Attention = 1;
						Bool_Quitter_Options = 1;
					}
					if (id == 121)
					{
						Bool_Quitter_Attention = 1;
					}
					if (id == 125)
					{
						Bool_Quitter_Attention2 = 1;
					}
					if (id == 150)
					{
						Bool_Choix_Taille_Grille = 1;
						Taille_Grille_ancienne = TailleGrille;
						TailleGrille = 25;
					}
					if (id == 151)
					{
						Bool_Choix_Taille_Grille = 1;
						Taille_Grille_ancienne = TailleGrille;
						TailleGrille = 35;
					}
					if (id == 152)
					{
						Bool_Choix_Taille_Grille = 1;
						Taille_Grille_ancienne = TailleGrille;
						TailleGrille = 45;
					}
					if (id == 153)
					{
						Bool_Choix_Taille_Grille = 1;
						Taille_Grille_ancienne = TailleGrille;
						TailleGrille = 55;
					}
					if (id == 154)
					{
						Bool_Fin_Taille_Grille = 1;
					}
					if (id == 210)
					{
						Bool_Valider_Condition = 1;
					}

				break;

				break;
			}
		}
		if (event.KeyInput.Key == KEY_KEY_S)
		{
			if (Bool_Choix_Cases == 0)
			{
				Bool_Choix_Cases = 1;
			}
		}
		if (event.KeyInput.Key == KEY_KEY_Q)
		{
			if(Bool_Choix_Cases == 1)
			{
				Bool_Choix_Fin = 1;
			}
		}

		return false;
	}
};

int main(void) {

    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<irr::u32>(800,600), 32, false, true, false, 0); // creation device // l'API est OpenGL // taille de la fenetre 800x600

		if (device == 0)
		return 1; // could not create selected driver.

    video::IVideoDriver* driver = device->getVideoDriver();                    // creation driver
    ISceneManager *sceneManager = device->getSceneManager ();                  // creation scene manager
	IGUIEnvironment* env = device->getGUIEnvironment();						   // création gui

	device->getCursorControl ()-> setVisible (true); // curseur visible
	device->setWindowCaption(L"Jeu de la Vie");

	//declaration variables
	
	vector<vector<vector<int > > > Grille(TailleGrilleMax, vector<vector<int> >(TailleGrilleMax, vector<int>(TailleGrilleMax, 0)));
	vector<vector<vector<int > > > Grille_Algo(TailleGrilleMax, vector<vector<int> >(TailleGrilleMax, vector<int>(TailleGrilleMax, 0)));
	vector<vector<vector<int > > > Grille_Test(TailleGrilleMax, vector<vector<int> >(TailleGrilleMax, vector<int>(TailleGrilleMax, 0)));

	//initialisation des principales variables
	int c=0,i=0,j=0,k=0;
	int x=0,y=0,z=0;
	int Nombres_Etapes = 1, Etapes = 1;
	int mouse_x = 0, mouse_y = 0;
	int Choix_ligne = 0, Choix_Cases = 0;
	int positionY = 0, positionX = 0, positionZ = 0;
	int Red = 100, Green = 100, Blue = 100;


	int TailleBlocs = 500/TailleGrille;

	//chargement des images - remplissage écran blanc

	irr::video::ITexture *image = driver->getTexture ("Cube.bmp");
	driver->makeColorKeyTexture (image, irr::video::SColor (0,255,255,255));

	IMeshSceneNode* Cubes[TailleGrilleMax][TailleGrilleMax][TailleGrilleMax];

	//remplissage de l'ensemble de la grille avec des cubes, invisible si la cellule est vide. 
	
	for (i=0; i<TailleGrille; i++)
	{
		for (j=0; j<TailleGrille; j++)
		{
			for (k=0; k<TailleGrille; k++)
			{
				Cubes[i][j][k] = sceneManager->addCubeSceneNode(1.0f,0,-1,vector3df((i-TailleGrille/2),(j-TailleGrille/2),(k-TailleGrille/2)));
				Cubes[i][j][k]->setMaterialTexture(0,image);
				Cubes[i][j][k]->getMaterial(0).EmissiveColor.set(255,255,0,0);
				Cubes[i][j][k]->setVisible(false);
			}
		}
	}	

	//Déclaration Cube sélection 1

	IMeshSceneNode* Cube_Choix_1 = sceneManager->addCubeSceneNode( 1.0f,0,-1,vector3df(0,0,0),vector3df(0,0,0),vector3df((TailleGrille+0.1),(TailleGrille+0.1),1));
	Cube_Choix_1->setMaterialTexture(0,driver->getTexture("Cube2.bmp"));
	Cube_Choix_1->setVisible(false);

	IMeshSceneNode* Cube_Choix_2 = sceneManager->addCubeSceneNode( 1.01f,0,-1);
	Cube_Choix_2->setMaterialTexture(0,driver->getTexture("Cube2.bmp"));
	Cube_Choix_2->setVisible(false);

	//variable pour la fonction aléatoire

	srand(time(0));
	int NombresCasesRemplies=0, NombresCasesConcerne=0, Pourcent=0, NbCase = 0;

	int Condition1 = 3, Condition2 = 4, ConditionVie1 = 4, ConditionVie2 = 4;

	//variable invariances

	int vérif_étapes=0, bool_vérif = 0, bool_différence = 0, grille_zero = 0, bool_4_trouvé = 0;

	//event

	MyEventReceiver receiver;
	device->setEventReceiver(&receiver);


	//éclairage

	sceneManager->setAmbientLight(video::SColorf(0.7, 0.7, 0.7, 0.0));   // ajout lumiere

	//Camera
	
	//Caméra fixe pour remplissage manuel
	ICameraSceneNode* Camera_Choix = sceneManager->addCameraSceneNode(sceneManager->getRootSceneNode(),vector3df(0,(TailleGrille + (TailleGrille/3)),0),vector3df(0,0,0));

	//Caméra Tracball pour déplacement scène
	ICameraSceneNode* camera = sceneManager->addCameraSceneNode(sceneManager->getRootSceneNode(), core::vector3df(40.0f, 100.0f, 40.0f), core::vector3df(0.0f, 0.0f, 0.0f));
	ISceneNodeAnimator* animator = new CSceneNodeAnimatorCameraTrackball(driver, device->getCursorControl(), 50, 4, 6);

	camera->addAnimator(animator);
	animator->drop(); 

	//GUI

	env->getSkin()->setFont(env->getFont("fontlucida.png")); //tout les éléments auront la même police

	IGUIElement* root = env->getRootGUIElement(); 

	IGUIButton *Quitter = env->addButton(
    irr::core::rect<irr::s32>(700,550,800,600),  // positoin du bouton quitter
    0, 101, L"Quitter");

	IGUIButton *Suivant = env->addButton(
    irr::core::rect<irr::s32>(0,550,100,600),  // positoin du bouton Etape suivante
    0, 102, L"Etape suivante");

	IGUIButton *Option = env->addButton(
    irr::core::rect<irr::s32>(100,550,200,600),  // positoin du bouton Options
    0, 103, L"Paramètres");

	IGUIButton *Stoper = env->addButton(
    irr::core::rect<irr::s32>(200,550,300,600),  // positoin du bouton Options
    0, 104, L"Stopper");

	IGUIButton *Invarriance = env->addButton(
    irr::core::rect<irr::s32>(300,550,400,600),  // positoin du bouton Options
    0, 105, L"Invarriance");

	IGUIWindow* Selection = env->addWindow(
        rect<s32>(100 + cnt, 100 + cnt, 400 + cnt, 150 + cnt), 
        false, // modal
		L"Selection", 0, 24);
	env->addStaticText(L" Pour Activer la selection, taper sur 'S'.",
		irr::core::rect<irr::s32>(5,20,400,50), false, true, Selection, -1, false);

	//Boucle rendu!

    while (device->run() && driver)  {  // la boucle de rendu   
		driver->beginScene( true, true, video::SColor(255,255,255,255));    // démarre le rendu // clear back-buffer // clear z-buffer // fond blanc
		
	
	if (quit == 0)
	{
		device->closeDevice();
	}

	//Options 

	if (Bool_Option == 1) 
	{
		Bool_Option = 0;

		//création de la fenètre option

		IGUIWindow* window = env->addWindow(
        rect<s32>(100 + cnt, 100 + cnt, 500 + cnt, 450 + cnt), 
        true, // modal
		L"Paramètres", 0, 20);

		//texte du menu option

		env->addStaticText(L" Remplissages aléatoire.",
		irr::core::rect<irr::s32>(5,40,225,60), false, true, window, -1, false);

		env->addStaticText(L" Nombre de Cases Concernées (%) : ",
		irr::core::rect<irr::s32>(5,70,225,90), false, true, window, -1, false);
		env->addStaticText(L" Pourcentages de cases concernées : ",
		irr::core::rect<irr::s32>(5,90,225,110), false, true, window, -1, false);

		env->addStaticText(L" Nombres d'étapes :",
		irr::core::rect<irr::s32>(5,160,225,180), false, true, window, -1, false);

		//box Cases Concernée

		irr::gui::IGUIEditBox *Edit_Box_CasesConcernes = env->addEditBox(
		L"", irr::core::rect<irr::s32>(225,70,270,90), true, window, 50);
		Edit_Box_CasesConcernes->setMax(3);
		
		//Box Pourcent

		irr::gui::IGUIEditBox *Edit_Box_Pourcent = env->addEditBox(
		L"", irr::core::rect<irr::s32>(225,90,270,110), true, window, 51);
		Edit_Box_Pourcent->setMax(3);

		//Box Nombres_Etapes

		irr::gui::IGUIEditBox *Edit_Box_Nombres_Etapes = env->addEditBox(
		L"", irr::core::rect<irr::s32>(225,160,270,180), true, window, 52);
		Edit_Box_Nombres_Etapes->setMax(4);

		//Bouton Valider_Remplissage_Aléatoire

		IGUIButton *Valider_Remplissage_Aléatoire = env->addButton(
		irr::core::rect<irr::s32>(280,70,380,110),  
		window, 106, L"Valider");

		//Bouton Valider_Nombres_Etapes

		IGUIButton *Valider_Nombres_Etapes = env->addButton(
		irr::core::rect<irr::s32>(280,150,380,190),  
		window, 107, L"Valider");
		
		//Bouton Taille Grille

		IGUIButton *Nombre_Etapes = env->addButton(
		irr::core::rect<irr::s32>(50,200,170,250),  
		window, 110, L"Taille Grille");
		
		//Bouton Conditions

		IGUIButton *Conditions = env->addButton(
		irr::core::rect<irr::s32>(190,200,310,250),  
		window, 111, L"Conditions");
		
		//Bouton Quitter_Options

		IGUIButton *Quitter_Options = env->addButton(
		irr::core::rect<irr::s32>(270,270,390,320),  
		window, 108, L"Quitter_Options");

		//Bouton remise a zéro

		IGUIButton *Remis_a_Zero = env->addButton(
		irr::core::rect<irr::s32>(100,270,220,320),  
		window, 109, L"Remis_a_Zero");

	}

	//Changement de la taille de la Grille

	if (Bool_Taille_Grille == 1)
	{
		Bool_Taille_Grille = 0;
		IGUIWindow* Taille_Grille_Wind = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Taille Grille", 0, 25);

			env->addStaticText(L"Choisissez la taille de la Grille.\n Attention, cela peut affecter les performances du programme.",rect<irr::s32>(25,20,600,100),false,false,Taille_Grille_Wind,200);

			IGUIButton *T25 = env->addButton(
			irr::core::rect<irr::s32>(100,75,150,115),  
			Taille_Grille_Wind, 150, L"T25");

			IGUIButton *T35 = env->addButton(
			irr::core::rect<irr::s32>(170,75,220,115),  
			Taille_Grille_Wind, 151, L"T35");

			IGUIButton *T45 = env->addButton(
			irr::core::rect<irr::s32>(250,75,300,115),  
			Taille_Grille_Wind, 152, L"T45");

			IGUIButton *T55 = env->addButton(
			irr::core::rect<irr::s32>(320,75,370,115),  
			Taille_Grille_Wind, 153, L"T55");

			IGUIButton *Valider = env->addButton(
			irr::core::rect<irr::s32>(390,75,440,115),  
			Taille_Grille_Wind, 154, L"Valider");

	}
	if (Bool_Choix_Taille_Grille == 1)
	{
		Bool_Choix_Taille_Grille = 0;
		Cube_Choix_1->setScale(vector3df((TailleGrille+0.1),(TailleGrille+0.1),1));
		Bool_Camera_position = 1;
		Bool_position = 1;
		TailleBlocs = 500/TailleGrille;

		if (Taille_Grille_ancienne < TailleGrille)
		{
			for (i=0; i<Taille_Grille_ancienne; i++)
			{
				for (j=0; j<Taille_Grille_ancienne; j++)
					{
					for (k=0; k<Taille_Grille_ancienne; k++)
					{
						if (Cubes[i][j][k])
						{
							Cubes[i][j][k]->remove();
						}
					}
				}
			}		
		
			for (i=0; i<TailleGrille; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Cubes[i][j][k] = sceneManager->addCubeSceneNode(1.0f,0,-1,vector3df((i-TailleGrille/2),(j-TailleGrille/2),(k-TailleGrille/2)));
						Cubes[i][j][k]->setMaterialTexture(0,image);
						Cubes[i][j][k]->getMaterial(0).EmissiveColor.set(255,255,0,0);
						Cubes[i][j][k]->setVisible(false);
					}
				}
			}
		
		for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille[i][j][k] = 0;
					}
				}
			}
		}
		else if (Taille_Grille_ancienne > TailleGrille)
		{
			for (i=0; i<Taille_Grille_ancienne; i++)
			{
				for (j=0; j<Taille_Grille_ancienne; j++)
					{
					for (k=0; k<Taille_Grille_ancienne; k++)
					{
						if (Cubes[i][j][k])
						{
							Cubes[i][j][k]->remove();
						}
					}
				}
			}		
		
			for (i=0; i<TailleGrille; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Cubes[i][j][k] = sceneManager->addCubeSceneNode(1.0f,0,-1,vector3df((i-TailleGrille/2),(j-TailleGrille/2),(k-TailleGrille/2)));
						Cubes[i][j][k]->setMaterialTexture(0,image);
						Cubes[i][j][k]->getMaterial(0).EmissiveColor.set(255,255,0,0);
						Cubes[i][j][k]->setVisible(false);
					}
				}
			}
		
		for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille[i][j][k] = 0;
					}
				}
			}
		}

	}
	if (Bool_Fin_Taille_Grille == 1)
	{
		Bool_Fin_Taille_Grille = 0;
		root->getElementFromId(25, true)->remove();
	}

	// Remise à zéro

	if (Bool_Remise_a_Zero == 1)
	{
		for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille[i][j][k] = 0;
					}
				}
			}
		Nombres_Etapes = 1;
		Bool_Remise_a_Zero = 0;
	}

	//Nombres d'étapes

	if (Bool_Valider_Nombres_Etapes == 1) //Gestions du bouton valider Nombres étapes.
	{
		Bool_Valider_Nombres_Etapes = 0;
		stringc Box_Nombres_Etapes;

		Box_Nombres_Etapes = root->getElementFromId(52, true)->getText();
		root->getElementFromId(52, true)->setText(L"");
		Nombres_Etapes = fast_atof(Box_Nombres_Etapes.c_str());

		if (Nombres_Etapes == 0) //gestion erreur de saisie lettres et 0
		{
			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"Au moins un des paramètres est à zéro!\n S'il s'agit d'une erreur, veuillez cliquer sur Annuler. Sinon, cliquez sur Continuer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Continuer = env->addButton(
			irr::core::rect<irr::s32>(190,100,290,140),  
			Erreur1, 120, L"Continuer");

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
	}

	// Conditions de vie et morts

	if (Bool_Conditions == 1)
	{
		Bool_Conditions = 0;

		IGUIWindow* Condition = env->addWindow(
		    rect<s32>(100 + cnt, 210 + cnt, 350 + cnt, 420 + cnt), 
		    true, // modal
			L"Condition", 0, 26);

		env->addStaticText(L"Condition1 :",
		irr::core::rect<irr::s32>(5,40,150,60), false, true, Condition, -1, false);

		env->addStaticText(L"Condition2 :",
		irr::core::rect<irr::s32>(5,70,225,90), false, true, Condition, -1, false);

		env->addStaticText(L"ConditionVie1 :",
		irr::core::rect<irr::s32>(5,100,225,120), false, true, Condition, -1, false);

		env->addStaticText(L"ConditionVie2 :",
		irr::core::rect<irr::s32>(5,130,225,150), false, true, Condition, -1, false);

		//box Condition1

		irr::gui::IGUIEditBox *Edit_Box_Condition1 = env->addEditBox(
		L"", irr::core::rect<irr::s32>(160,40,200,60), true, Condition, 200);
		Edit_Box_Condition1->setMax(2);
		
		//Box Pourcent

		irr::gui::IGUIEditBox *Edit_Box_Condition2 = env->addEditBox(
		L"", irr::core::rect<irr::s32>(160,70,200,90), true, Condition, 201);
		Edit_Box_Condition2->setMax(2);

		//Box Pourcent

		irr::gui::IGUIEditBox *Edit_Box_ConditionVie1 = env->addEditBox(
		L"", irr::core::rect<irr::s32>(160,100,200,120), true, Condition, 202);
		Edit_Box_ConditionVie1->setMax(2);

		//Box Pourcent

		irr::gui::IGUIEditBox *Edit_Box_ConditionVie2 = env->addEditBox(
		L"", irr::core::rect<irr::s32>(160,130,200,150), true, Condition, 203);
		Edit_Box_ConditionVie2->setMax(2);

		//Bouton Valider_Condition

		IGUIButton *Valider_Condition = env->addButton(
		irr::core::rect<irr::s32>(150,160,200,200),  
		Condition, 210, L"Valider");
		
		
	}

	if (Bool_Valider_Condition == 1)
	{
		Bool_Valider_Condition = 0;

		int Condition1_Prec = Condition1;
		int Condition2_Prec = Condition2;
		int ConditionVie1_Prec = ConditionVie1;
		int ConditionVie2_Prec = ConditionVie2;

		stringc Box_Condition1;
		stringc Box_Condition2;
		stringc Box_ConditionVie1;
		stringc Box_ConditionVie2;

		Box_Condition1 = root->getElementFromId(200, true)->getText();
		root->getElementFromId(200, true)->setText(L"");
		Condition1 = fast_atof(Box_Condition1.c_str());

		Box_Condition2 = root->getElementFromId(201, true)->getText();
		root->getElementFromId(201, true)->setText(L"");
		Condition2 = fast_atof(Box_Condition2.c_str());

		Box_ConditionVie1 = root->getElementFromId(202, true)->getText();
		root->getElementFromId(202, true)->setText(L"");
		ConditionVie1 = fast_atof(Box_ConditionVie1.c_str());

		Box_ConditionVie2 = root->getElementFromId(203, true)->getText();
		root->getElementFromId(203, true)->setText(L"");
		ConditionVie2 = fast_atof(Box_ConditionVie2.c_str());

		Bool_Condition_Quitte = 1;

		if (Condition1 == 0) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			Condition1 = Condition1_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de survie 1 est à zéro!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (Condition2 == 0) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			Condition2 = Condition2_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de survie 1 est à zéro!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (ConditionVie1 == 0) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			ConditionVie1 = ConditionVie1_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de naissance 1 est à zéro!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (ConditionVie2 == 0) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			ConditionVie2 = ConditionVie2_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de naissance 2 est à zéro!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (Condition1 > 25) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			Condition1 = Condition1_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de survie 1 est supèrieur à 25!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (Condition2 > 25) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			Condition2 = Condition2_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de survie 1 est supèrieur à 25!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (ConditionVie1 > 25) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			ConditionVie1 = ConditionVie1_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de naissance 1 est supèrieur à 25!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		if (ConditionVie2 > 25) //gestion erreur de saisie lettres et 0
		{
			Bool_Condition_Quitte = 0;
			ConditionVie2 = ConditionVie2_Prec;

			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"La condition de naissance 2 est supèrieur à 25!\n Veuillez la changer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
	}
		

	//Remplissage aléatoire

	if (Bool_Valider_Remplissage_Aléatoire == 1) //Gestions du bouton valider du remplissage aléatoire
	{
		Bool_Valider_Remplissage_Aléatoire = 0;
		stringc Box_CasesConcernes;	
		stringc Box_Pourcent;

		Box_CasesConcernes = root->getElementFromId(50, true)->getText();
		root->getElementFromId(50, true)->setText(L"");
   		NombresCasesConcerne = fast_atof(Box_CasesConcernes.c_str());

		Box_Pourcent = root->getElementFromId(51, true)->getText();
		root->getElementFromId(51, true)->setText(L"");
		Pourcent = fast_atof(Box_Pourcent.c_str());

		if (NombresCasesConcerne == 0 || Pourcent == 0) //gestion erreur de saisie lettres et 0
		{
			IGUIWindow* Erreur1 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 21);

			env->addStaticText(L"Au moins un des paramètres est à zéro!\n S'il s'agit d'une erreur, veuillez cliquer sur Annuler. Sinon, cliquez sur Continuer.",rect<irr::s32>(25,20,600,100),false,false,Erreur1,200);

			IGUIButton *Continuer = env->addButton(
			irr::core::rect<irr::s32>(190,100,290,140),  
			Erreur1, 120, L"Continuer");

			IGUIButton *Annuler = env->addButton(
			irr::core::rect<irr::s32>(310,100,410,140),  
			Erreur1, 121, L"Annuler");
		}
		else if (NombresCasesConcerne > 100 || Pourcent > 100 || NombresCasesConcerne < 0 || Pourcent < 0 ) //gestion erreur de saisie nombre > ou <
		{
			IGUIWindow* Erreur2 = env->addWindow(
		    rect<s32>(100 + cnt, 200 + cnt, 700 + cnt, 350 + cnt), 
		    true, // modal
			L"Attention", 0, 22);

			env->addStaticText(L"\n Veuillez entrer un nombre compris entre 1 et 100.",rect<irr::s32>(25,20,600,100),false,false,Erreur2,200);

			IGUIButton *Continuer2 = env->addButton(
			irr::core::rect<irr::s32>(250,100,350,140),  
			Erreur2, 125, L"Ok");
		}
		else //saisie bonne 
		{

			//Remplissage aléatoire
			
			int i=0,j=0,k=0, NbCase = 0, NombresCasesRemplies = 0;
			NombresCasesConcerne = (TailleGrille*NombresCasesConcerne)/100;
			if (NombresCasesConcerne == 0)
			{
				NombresCasesConcerne = 1;
			}

			NbCase = ((Pourcent*NombresCasesConcerne*NombresCasesConcerne*NombresCasesConcerne)/100);

			for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille[i][j][k] = 0;
					}
				}
			}

			do
		    {
		      i = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
		      j = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
			  k = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
		     if (Grille[i][j][k] == 0)
		     {
				 Grille[i][j][k] = 1;
				 NombresCasesRemplies ++;
		     }
		    }while(NombresCasesRemplies < NbCase );

			root->getElementFromId(20, true)->remove();
			Bool_Affichage_cube = 1;
		}

	}
	if (Bool_Quitter_Attention == 1)
	{
		Bool_Quitter_Attention = 0;
		root->getElementFromId(21, true)->remove();
	}
	if (Bool_Quitter_Attention2 == 1)
	{
		Bool_Quitter_Attention2 = 0;
		root->getElementFromId(22, true)->remove();
	}
	if (Bool_Quitter_Options == 1)
	{
		Bool_Quitter_Options = 0; 
		root->getElementFromId(20, true)->remove();
		Bool_Affichage_cube = 1;
	}
	if (Bool_Condition_Quitte == 1)
	{
		Bool_Condition_Quitte = 0;
		root->getElementFromId(26, true)->remove();
	}

	//algorithme

	if (Bool_Algo == 1)
	{

		int i=0,j=0,k=0, NombreAlentour = 0;

		for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille_Algo[i][j][k] = Grille[i][j][k] ;
					}
				}
			}

		Red = (rand() % (255));
		Green = (rand() % (255));
		Blue = (rand() % (255));
	
	for (i=0 ; i<TailleGrille ; i++)
	{
		for (j=0; j<TailleGrille; j++)
		{
			for (k=0; k<TailleGrille; k++)
			{
				if (Grille_Algo[i][j][k] == 1)
				{
					if((i-1)>=0 && (j-1)>=0 && (k-1)>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][(j-1)][(k-1)] == 1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j-1)>=0 && k>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][(j-1)][k] == 1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j-1)>=0 && (k+1)>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][(j-1)][(k+1)]==1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && (k-1)>=0 && (i-1)<TailleGrille && j<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][j][(k-1)]==1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && k>=0 && (i-1)<TailleGrille && j<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][j][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && (k+1)>=0 && (i-1)<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && (k-1)>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && k>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && (k+1)>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					//fin i-1
					if(i>=0 && (j-1)>=0 && (k-1)>=0 && i<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][(j-1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j-1)>=0 && k>=0 && i<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[i][(j-1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j-1)>=0 && (k+1)>=0 && i<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][(j-1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && j>=0 && (k-1)>=0 && i<TailleGrille && j<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][j][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && j>=0 && (k+1)>=0 && i<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && (k-1)>=0 && i<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && k>=0 && i<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[i][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && (k+1)>=0 && i<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					//fin i
					if((i+1)>=0 && (j-1)>=0 && (k-1)>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i+1)][(j-1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j-1)>=0 && k>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][(j-1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j-1)>=0 && (k+1)>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][(j-1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && (k-1)>=0 && (i+1)<TailleGrille && j<TailleGrille&& (k-1)<TailleGrille && Grille_Algo[(i+1)][j][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && k>=0 && (i+1)<TailleGrille && j<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][j][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && (k+1)>=0 && (i+1)<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && (k-1)>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i+1)][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && k>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && (k+1)>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if (Condition1 < Condition2)
					{
					if (NombreAlentour >= Condition1 && NombreAlentour <= Condition2)
					{
						Grille[i][j][k]=1;
						NombreAlentour = 0;
					}
					else
					{
						Grille[i][j][k]=0;
						NombreAlentour = 0;
					}
					}
					else 
					{
					if (NombreAlentour >= Condition2  && NombreAlentour <= Condition1)
					{
						Grille[i][j][k]=1;
						NombreAlentour = 0;
					}
					else
					{
						Grille[i][j][k]=0;
						NombreAlentour = 0;
					}
					}				
				NombreAlentour = 0;
				}
				else
				{
					if((i-1)>=0 && (j-1)>=0 && (k-1)>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][(j-1)][(k-1)] == 1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j-1)>=0 && k>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][(j-1)][k] == 1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j-1)>=0 && (k+1)>=0 && (i-1)<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][(j-1)][(k+1)]==1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && (k-1)>=0 && (i-1)<TailleGrille && j<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][j][(k-1)]==1)
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && k>=0 && (i-1)<TailleGrille && j<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][j][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && j>=0 && (k+1)>=0 && (i-1)<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && (k-1)>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i-1)][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && k>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[(i-1)][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i-1)>=0 && (j+1)>=0 && (k+1)>=0 && (i-1)<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i-1)][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					//fin i-1
					if(i>=0 && (j-1)>=0 && (k-1)>=0 && i<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][(j-1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j-1)>=0 && k>=0 && i<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[i][(j-1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j-1)>=0 && (k+1)>=0 && i<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][(j-1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && j>=0 && (k-1)>=0 && i<TailleGrille && j<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][j][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && j>=0 && (k+1)>=0 && i<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && (k-1)>=0 && i<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[i][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && k>=0 && i<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[i][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if(i>=0 && (j+1)>=0 && (k+1)>=0 && i<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[i][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					//fin i
					if((i+1)>=0 && (j-1)>=0 && (k-1)>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i+1)][(j-1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j-1)>=0 && k>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][(j-1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j-1)>=0 && (k+1)>=0 && (i+1)<TailleGrille && (j-1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][(j-1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && (k-1)>=0 && (i+1)<TailleGrille && j<TailleGrille&& (k-1)<TailleGrille && Grille_Algo[(i+1)][j][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && k>=0 && (i+1)<TailleGrille && j<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][j][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && j>=0 && (k+1)>=0 && (i+1)<TailleGrille && j<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][j][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && (k-1)>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && (k-1)<TailleGrille && Grille_Algo[(i+1)][(j+1)][(k-1)]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && k>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && k<TailleGrille && Grille_Algo[(i+1)][(j+1)][k]==1 )
					{
						NombreAlentour ++;
					}
					if((i+1)>=0 && (j+1)>=0 && (k+1)>=0 && (i+1)<TailleGrille && (j+1)<TailleGrille && (k+1)<TailleGrille && Grille_Algo[(i+1)][(j+1)][(k+1)]==1 )
					{
						NombreAlentour ++;
					}
					if (NombreAlentour == ConditionVie1 || NombreAlentour == ConditionVie2)
					{
						Grille[i][j][k]=1;
						NombreAlentour = 0;
						Cubes[i][j][k]->getMaterial(0).EmissiveColor.set(255,Red,Green,Blue);
					}
					else
					{
						Grille[i][j][k]=0;
						NombreAlentour = 0;
					}

					NombreAlentour =0;
				}
			}
		}
	}

	Sleep(100);
	Bool_Algo = 0;
	Bool_Affichage_cube = 1;
	}

	//Etapes de l'algo
	
	if (Etapes < Nombres_Etapes && Bool_Lancement_Algo == 1) 
	{
		Etapes ++;
		Bool_Algo = 1;
	}
	else
	{
		Bool_Lancement_Algo = 0;
		Etapes = 1;
	}

	//trouver les invariances

	if (Bool_Invaiance_création_grille == 1)
	{
		printf("début invariance");

		int i=0,j=0,k=0;

		for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille_Test[i][j][k] = Grille[i][j][k] ;
					}
				}
			}

		Bool_Invaiance_création_grille = 0;
		Etapes = 1;
		Nombres_Etapes = 25;
		Bool_Lancement_Algo = 1;
		Bool_Invaiance = 1;
		bool_différence = 0;
		bool_vérif = 0;
		vérif_étapes = 0;

		bool_création_fenetre_invariance = 1;
	}

	if(Bool_Invaiance == 1)
	{
			cout << "\n vérif étapes" << vérif_étapes <<  endl;
			cout << "\n étapes" << Etapes <<  endl;
			
			int i=0,j=0,k=0;

			for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						if (Grille[i][j][k] == 1)
						{
							if (Grille_Test[i][j][k] == 4)
							{
								Grille_Test[i][j][k] = 4;
								bool_vérif = 1;
							}
							else 
							{
								Grille_Test[i][j][k] ++;
								bool_différence = 1;
							}
						}
						else
						{
							if (Grille_Test[i][j][k] == 0)
							{
								Grille_Test[i][j][k] = 0;
							}
							else
							{
								Grille_Test[i][j][k] = 0;
								bool_différence = 1;
							}
						}
					}
				}
			}

			if(bool_différence == 1)
			{
				bool_différence = 0;
				bool_vérif = 0;
				vérif_étapes = 0;
			}

			if (bool_vérif == 1)
			{
				bool_vérif = 0;
				vérif_étapes ++;
			}

			for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						if (Grille_Test[i][j][k] == 4)
						{
							bool_4_trouvé = 1;
							i = 25;
							j = 25;
							k = 25;
						}
					}
				}
			}

			if (bool_4_trouvé == 1)
			{
				bool_4_trouvé = 0;
				for (i=0 ; i<TailleGrille ; i++)
				{
					for (j=0; j<TailleGrille; j++)
					{
						for (k=0; k<TailleGrille; k++)
						{
							if (Grille_Test[i][j][k] == 4)
							{
								Grille[i][j][k] = 1;
							}
							else
							{
								Grille[i][j][k] = 0;
							}
						}
					}
				}
			}
	
			
		//la grille est tout à zéro?

		for (i=0 ; i<TailleGrille ; i++)
		{
			for (j=0; j<TailleGrille; j++)
			{
				for (k=0; k<TailleGrille; k++)
				{
					if (Grille[i][j][k] == 0)
					{
						grille_zero ++;
					}
				}
			}
		}

		if(grille_zero == (TailleGrille*TailleGrille*TailleGrille))
		{
			vérif_étapes = 0;
			Etapes = Nombres_Etapes;
		}

		if(vérif_étapes == 4)
		{
			Bool_Invaiance = 0;
			vérif_étapes = 0;
			bool_différence = 0;
			bool_vérif = 0;
			Bool_Algo = 0;
			Bool_Lancement_Algo = 0;
			bool_quitter_fenetre_invariance = 1;
			bool_création_fenetre_invariance_trouvé = 1;
			grille_zero = 0;
		}
		else if (Etapes == Nombres_Etapes)
		{
			vérif_étapes = 0;
			bool_différence = 0;
			bool_vérif = 0;
			Bool_Invaiance_création_grille = 1;
			bool_quitter_fenetre_invariance = 1;
			grille_zero = 0;

			//Remplissage aléatoire
			
			int i=0,j=0,k=0, NbCase = 0, NombresCasesRemplies = 0, NombresCasesConcerne = 100, Pourcent = 3;
			NombresCasesConcerne = (TailleGrille*NombresCasesConcerne)/100;
			if (NombresCasesConcerne == 0)
			{
				NombresCasesConcerne = 1;
			}

			NbCase = ((Pourcent*NombresCasesConcerne*NombresCasesConcerne*NombresCasesConcerne)/100);

			for (i=0 ; i<TailleGrille ; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						Grille[i][j][k] = 0;
					}
				}
			}

			do
		    {
		      i = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
		      j = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
			  k = (rand() % (NombresCasesConcerne)) + (TailleGrille)/2 - NombresCasesConcerne/2;
		     if (Grille[i][j][k] == 0)
		     {
				 Grille[i][j][k] = 1;
				 NombresCasesRemplies ++;
		     }
		    }while(NombresCasesRemplies < NbCase );

		}

	}

	if(bool_création_fenetre_invariance == 1)
	{
		bool_création_fenetre_invariance = 0;
		IGUIWindow* invariance = env->addWindow(
		    rect<s32>(100 + cnt, 100 + cnt, 400 + cnt, 150 + cnt), 
		    false, // modal
			L"Recherche Invariance en cours...", 0, 28);

			env->addStaticText(L"Recherche d'invariance en cours...",rect<irr::s32>(5,20,400,50),false,false,invariance,200);
	}

	if (bool_quitter_fenetre_invariance == 1)
	{
		bool_quitter_fenetre_invariance = 0;
		root->getElementFromId(28, true)->remove();
	}

	if(bool_création_fenetre_invariance_trouvé == 1)
	{
		bool_création_fenetre_invariance_trouvé = 0;
		IGUIWindow* invariance_trouvé = env->addWindow(
		    rect<s32>(100 + cnt, 100 + cnt, 500 + cnt, 150 + cnt), 
		    false, // modal
			L"Invariance(s) trouvée(s)", 0, 29);

			env->addStaticText(L"Une ou plusieurs figure(s) d'invariance(s) ont été trouvée(s).",rect<irr::s32>(5,20,500,50),false,false,invariance_trouvé,200);
	}


	//Remplissage manuel de la grille

	if (Bool_Choix_Cases == 1)
	{
		sceneManager->setActiveCamera(Camera_Choix);
		if (Bool_Camera_position == 1)
		{
			Camera_Choix->setPosition(vector3df(0,-(TailleGrille + (TailleGrille/3)),0));
			Bool_Camera_position = 0;
		}
		Cube_Choix_1->setVisible(true);
		Cube_Choix_2->setVisible(false);
	
		for (i=0; i<TailleGrille; i++)
		{
			for (j=0; j<TailleGrille; j++)
			{
				for (k=0; k<TailleGrille; k++)
				{
					Cubes[i][j][k]->setVisible(false);
				}
			}
		}

		for (i=0; i<TailleGrille; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						if (Grille[i][j][k] == 1)
						{
							Cubes[i][j][k]->setVisible(true);
						}
					}
				}
			}

		if (Bool_Mouvement == 1)
		{
			Bool_Mouvement = 0;
			if (Bool_position == 0)
			{
			positionY = -((mouse.X - 150)/(TailleBlocs) - (TailleGrille/2));
			if (positionY > (TailleGrille/2))
				{
					positionY = (TailleGrille/2);
				}
				if (positionY < -(TailleGrille/2))
				{
					positionY = -(TailleGrille/2);
				}
			}
			else if (Bool_position == 1)
			{
			positionY = ((mouse.X - 150)/(TailleBlocs) - (TailleGrille/2));
			}
			if (positionY > (TailleGrille/2))
				{
					positionY = (TailleGrille/2);
				}
				if (positionY < -(TailleGrille/2))
				{
					positionY = -(TailleGrille/2);
				}
			if (positionY >= -(TailleGrille/2) && positionY <= (TailleGrille/2))
			{
			Cube_Choix_1->setPosition(vector3df(0,0,(f32)(positionY)));
			}
		}
		if (Bool_Clique_Souris == 1)
		{
			Bool_Clique_Souris = 0;
			if (mouse.Y >=51 && mouse.Y <= 549)
			{
				if (mouse.X >= 151 && mouse.X <= 649)
				{
				positionY = ((mouse.X - 150)/(TailleBlocs));
				if (positionY > (TailleGrille-1))
				{
					positionY = (TailleGrille-1);
				}
				if (positionY < 1)
				{
					positionY = 0;
				}
				Bool_Choix_Cases2 = 1;
				Bool_Choix_Cases = 0;
				}
			}
		}
	}
	if (Bool_Choix_Cases2 == 1)
	{
		Bool_Choix_Cases = 0;
		Camera_Choix->setPosition(vector3df(0,0, -(TailleGrille + (TailleGrille/3) - positionY)));
		Cube_Choix_1->setVisible(false);
		Cube_Choix_2->setVisible(true);

		for (i=0; i<TailleGrille; i++)
		{
			for (j=0; j<TailleGrille; j++)
			{
				for (k=0; k<TailleGrille; k++)
				{
					Cubes[i][j][k]->setVisible(false);
				}
			}
		
		}


		for (i=0; i<TailleGrille; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=positionY; k<TailleGrille; k++)
					{
						if (Grille[i][j][k] == 1)
						{
							Cubes[i][j][k]->setVisible(true);
						}
					}
				}
			}

		//Cube_Choix_2
		if (Bool_Mouvement == 1)
		{
			Bool_Mouvement = 0;
			positionX = ((mouse.X - 150)/(TailleBlocs)-(TailleGrille/2));
			positionZ = -((mouse.Y - 50)/(TailleBlocs)-(TailleGrille/2));
			if (positionZ >= -(TailleGrille/2) && positionZ <= (TailleGrille/2) && positionX >= -(TailleGrille/2) && positionX <= (TailleGrille/2))
			{
			Cube_Choix_2->setPosition(vector3df((f32)positionX,(f32)positionZ,(f32)(positionY - (TailleGrille/2))));
			}
		}
		if (Bool_Clique_Souris2 == 1)
		{
			Bool_Clique_Souris2 = 0;
			if (mouse.Y >=51 && mouse.Y <= 549)
			{
				if (mouse.X >= 151 && mouse.X <= 649)
				{
				positionX = ((mouse.X - 150)/(TailleBlocs));
				if (positionX > (TailleGrille-1))
				{
					positionX = (TailleGrille-1);
				}
				if (positionX < 1)
				{
					positionX = 0;
				}
				positionZ = (-(mouse.Y - 50)/(TailleBlocs) + (TailleGrille-1));
				if (positionZ > TailleGrille)
				{
					positionZ = TailleGrille;
				}
				if (positionZ < 1)
				{
					positionZ = 0;
				}
				Bool_Remplissage_Case = 1;
				}
			}
		}
	}
	if (Bool_Remplissage_Case == 1)
	{
		if (Grille[positionX][positionZ][positionY] == 1)
		{
		Grille[positionX][positionZ][positionY] = 0;
		Bool_Remplissage_Case = 0;
		}
		else
		{
		Grille[positionX][positionZ][positionY] = 1;
		Bool_Remplissage_Case = 0;
		}

	}
	if (Bool_Choix_Fin == 1)
	{
		Bool_Choix_Fin = 0;
		Bool_Choix_Cases = 0;
		Bool_Affichage_cube = 1;
		Cube_Choix_1->setVisible(false);
		Cube_Choix_2->setVisible(false);
		sceneManager->setActiveCamera(camera);
	}


	//affichage

	if (Bool_Affichage_cube == 1)
	{
		//rends les cubes invisibles

	for (i=0; i<TailleGrille; i++)
	{
		for (j=0; j<TailleGrille; j++)
		{
			for (k=0; k<TailleGrille; k++)
			{
				Cubes[i][j][k]->setVisible(false);
			}
		}
	}	

		//rends les cubes visibles

			for (i=0; i<TailleGrille; i++)
			{
				for (j=0; j<TailleGrille; j++)
				{
					for (k=0; k<TailleGrille; k++)
					{
						if (Grille[i][j][k] == 1)
						{
							Cubes[i][j][k]->setVisible(true);
						}
					}
				}
			}	

	Bool_Affichage_cube = 0;
	}

	//fin

        sceneManager->drawAll ();                    // calcule le rendu
		env->drawAll();						         //affiche la gui
        driver->endScene ();						 // affiche le rendu
	}

	for (i=0; i<TailleGrille; i++)
	{
		for (j=0; j<TailleGrille; j++)
		{
			for (k=0; k<TailleGrille; k++)
			{
				if (Cubes[i][j][k])
				{
					Cubes[i][j][k]->remove();
				}
			}
		}
	}	

    device->drop ();                                 // liberation de la memoire
    return 0;
}
