#pragma once

#include <iostream>
#include <limits>
#include <Windows.h>

using namespace std;

class game
{
public:
    // hero
    int hp;
    int mana;
    int dmg;
    int def;
    int xp;
    int rep;
    int lvl;
    string name;
    int attack(int ehp, int dmg);
    int chargeattack(int ehp, int dmg);
    int details(int dmg, int hp, int def, int xp, int lvl, int rep, string name);
    void title(int rep);
    int xpup(int xp);
    int hpup(int hp);
    int dmgup(int dmg);
    int lvlup(int lvl);
    int defup(int def);

    // enemy
    int ehp;
    int edmg;
    int edef;
    int eattack(int edmg, int def, int hp);
};

int OptionChooseFunc(int optionMinLimit, int optionMaxLimit)
{
    int option;
    while (true)
    {
        cout << "Input: ";
        cin >> option;
        try
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw option;
            }
            else if (option < optionMinLimit || option > optionMaxLimit)
            {
                throw option;
            }
            else
            {
                break;
            }
        }
        catch (int option)
        {
            cout << "Wrong input!" << endl;
        }
    }
    return option;
}

int game::attack(int ehp, int dmg)
{
    ehp = ehp - dmg;
    return ehp;
}

int game::chargeattack(int ehp, int dmg)
{
    ehp = ehp - dmg*1.5;
    return ehp;
}

int game::eattack(int edmg, int def, int hp)
{
    edmg = def - edmg;
    if (edmg < 0)
        edmg = -1 * edmg;
    else
        edmg = 0;
    hp = hp - edmg;
    return hp;
}

int game::details(int dmg, int hp, int def, int xp, int lvl, int rep, string name)
{
    int menuoption;
    system("cls");
    cout<<"   Detalii:"<<endl
        <<"Nume: "<<name<<endl
        <<"Lvl: "<<lvl<<"   "<<xp<<"/50"<<endl
        <<"Hp: "<<hp<<endl
        <<"Atk: "<<dmg<<endl
        <<"Def: "<<def<<endl
        <<"Rep: "<<rep<<endl<<endl
        <<"0.Back"<<endl;
    menuoption = OptionChooseFunc(0,0);
    return menuoption;
}

void game::title(int rep)
{
    cout<<"    Titluri:"<<endl;
    if(rep==0)
        cout<<"-Narcisist"<<endl;
    else if(rep<0 && rep>-50)
        cout<<"-Om rau"<<endl;
    else if(rep<=-50)
        cout<<"-Om putred"<<endl;
    else if(rep>0 && rep<50)
        cout<<"-Om bun"<<endl;
    else if(rep>=50)
        cout<<"-Om foarte bun"<<endl;
}

int combat(int ehp, int dmg, int edmg, int def, int hp, int rep)
{
    while(hp>0 && ehp>0)
    {
        game warrior, wolf, father;
        int menuoption;
        system("cls");
        cout<<"Your hp: "<<hp<<"          "<<"Enemy hp:"<<ehp<<endl;
        cout<<"Select the attack"<<endl;
        cout<<"1.Quick attack"<<endl;
        cout<<"2.Charge attack"<<endl;
        menuoption = OptionChooseFunc(1,2);
        if(menuoption==1)
        {
            ehp=warrior.attack(ehp, dmg);
            if(ehp<=0)
            {
                system("cls");
                cout<<" Felicitari, ai castigat aceasta lupta"<<endl;
                rep=rep+10;
                return rep;
            }
            else
            {
                hp = father.eattack(edmg, def, hp);
                if(hp<=0)
                {
                    system("cls");
                    cout<<"GAME OVER"<<endl;
                    warrior.title(rep);
                    exit(1);
                }
            }
        }
        else if(menuoption==2)
        {
            hp = father.eattack(edmg, def, hp);
            if(hp<=0)
            {
                system("cls");
                cout<<"GAME OVER"<<endl;
                warrior.title(rep);
                exit(1);
            }
            ehp=warrior.chargeattack(ehp, dmg);
            if(ehp<=0)
            {
                system("cls");
                cout<<" Felicitari, ai castigat aceasta lupta"<<endl;
                rep=rep+10;
                return rep;
            }
        }
    }
}

int combatinfo(int ehp, int dmg, int edmg, int def, int hp, int rep,int edef)
{
    while(hp>0 && ehp>0)
    {
        game warrior, wolf, father;
        int menuoption;
        system("cls");
        cout<<"Your hp:  "<<hp<<"          "<<"Enemy hp: "<<ehp<<endl;
        cout<<"     dmg: "<<dmg<<"            "<<"     dmg: "<<edmg<<endl;
        cout<<"     def: "<<def<<"          "<<"      def: "<<edef<<endl;
        cout<<"Select the attack"<<endl;
        cout<<"1.Quick attack"<<endl;
        cout<<"2.Charge attack"<<endl;
        menuoption = OptionChooseFunc(1,2);
        if(menuoption==1)
        {
            ehp=warrior.eattack(dmg, edef, ehp);
            if(ehp<=0)
            {
                system("cls");
                cout<<" Felicitari, ai castigat aceasta lupta"<<endl;
                rep=rep+10;
                return rep;
            }
            else
            {
                hp = father.eattack(edmg, def, hp);
                if(hp<=0)
                {
                    system("cls");
                    cout<<"GAME OVER"<<endl;
                    warrior.title(rep);
                    exit(1);
                }
            }
        }
        else if(menuoption==2)
        {
            hp = father.eattack(edmg, def, hp);
            if(hp<=0)
            {
                system("cls");
                cout<<"GAME OVER"<<endl;
                warrior.title(rep);
                exit(1);
            }
            ehp=warrior.eattack(dmg, edef, ehp);
            if(ehp<=0)
            {
                system("cls");
                cout<<" Felicitari, ai castigat aceasta lupta"<<endl;
                rep=rep+10;
                return rep;
            }
        }
    }
}

int game::xpup(int xp)
{
    if(xp>=50)
        xp=xp-50;
    return xp;
}

int game::hpup(int hp)
{
    hp=hp*1.1;
    return hp;
}

int game::dmgup(int dmg)
{
    dmg=dmg*1.3;
    return dmg;
}

int game::defup(int def)
{
    def=def*1.5;
    return def;
}

int game::lvlup(int lvl)
{
    lvl++;
    return lvl;
}



int main()
{
    game wolf, orc, slime, warrior, father;
    father.ehp=35;
    father.edmg=7;
    wolf.ehp = 25;
    wolf.edmg = 6;
    wolf.edef=2;
    orc.ehp=35;
    orc.edmg=7;
    orc.edef=3;
    slime.ehp=20;
    slime.edmg=5;
    slime.edef=0;

    int menuoption;
    int checkpoint;
    int addxp;

menu:
    cout << "The swordsman v1.0.1 (Beta)" << endl<< endl;
    cout << "    MENU    " << endl<< endl;
    cout << "1. Start" << endl;
    cout << "2. Help" << endl;
    cout << "0. Quit" << endl;

    menuoption = OptionChooseFunc(0,2);

    switch (menuoption)
    {
    case 1:
        system("cls");
ngame:
        cout<<"1. Start a new game"<<endl;
        //momentan salvarile jocului functioneaza doar daca nu inchidem consola
        cout<<"2. Continue game"<<endl<<endl;
        cout<<"0. Back"<<endl;
        menuoption = OptionChooseFunc(0,2);
        if(menuoption==1)
        {
            system("cls");
            cout<<" Do you want to start a new game?"<<endl
                <<"1.Yes"<<endl
                <<"2.No"<<endl;
            menuoption = OptionChooseFunc(1,2);
            if(menuoption==1)
            {
                /*Joc*/

                checkpoint=0;
check0:

                warrior.hp = 50;
                warrior.dmg = 5;
                warrior.def = 3;
                warrior.xp=0;
                warrior.lvl=1;
                warrior.rep=0;

                system("cls");
                cout<<" Introduceti numele eroului"<<endl;
                getline(cin,warrior.name);
                getline(cin,warrior.name);

                cout<<" La marginea regatului Chingdam este un sat numit Viligi unde se afla un maestru spadasin"<<endl
                    <<"impreuna cu familia sa, sotia si fiul lor "<<warrior.name<<". Tanarul a fost supus unui"<<endl
                    <<"antrenament foarte greu care i-a dezvoltat abilitatile cu sabia, devenind la fel de bun ca"<<endl
                    <<"si tatal sau. La varsta de 16 ani "<<warrior.name<<" a avut un duel cu tatal sau ca sa-i"<<endl
                    <<"demonstreze ca este capabil sa plece in capitala regatului Chingdam."<<endl;
                cout<<endl<<"Enter 1 to start"<<endl;
                menuoption = OptionChooseFunc(1,1);
                if(menuoption==1)
                {
                    system("cls");
                    warrior.rep=combat(father.ehp, warrior.dmg, father.edmg, warrior.def, warrior.hp, warrior.rep);
                }

                checkpoint++;
check1:

                cout<<"1.Continue"<<endl
                    <<"2.Hero details"<<endl
                    <<"3.Back to menu"<<endl;
                menuoption = OptionChooseFunc(1,3);
                if(menuoption==2)
                {
                    menuoption=warrior.details(warrior.dmg, warrior.hp, warrior.def, warrior.xp, warrior.lvl, warrior.rep, warrior.name);
                    if (menuoption==0)
                    {
                        system ("cls");
                        goto salvare;
                    }
                    system("cls");
                }
                else if(menuoption==3)
                {
                    system ("cls");
                    goto menu;
                }
                else if(menuoption==1)
                {
                    system("cls");
                    cout<<"Tatal: Fiule, ai dovedit ca esti destul de puternic pentru a merge in capitala regala."<<endl
                        <<warrior.name<<": Multumesc tata pentru indrumare si promit sa nu te desamagesc."<<endl
                        <<"Tatal: Sunt sigur de asta, sa ai o calatorie placuta."<<endl<<endl
                        <<"1.Continue"<<endl;
                    menuoption = OptionChooseFunc(1,1);
                    if(menuoption==1)
                    {
                        system("cls");
                        cout<<" Astfel incepe drumul lui "<<warrior.name<<" pana in capitala regala. Pe drumul"<<endl
                            <<"sau spre capitala se intalneste cu un lup monstru care fugea speriat de ceva."<<endl;
                        cout<<"1.Lupta"<<endl
                            <<"2.Ascundete"<<endl;
                        menuoption = OptionChooseFunc(1,2);
                        if (menuoption==1)
                        {
                            system("cls");
                            warrior.rep=combat(wolf.ehp, warrior.dmg, wolf.edmg, warrior.def, warrior.hp, warrior.rep);
                            warrior.xp+=20;
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                        }
                        else if (menuoption==2)
                        {
                            system("cls");
                            cout<<" Te-ai ascuns iar lupul a fugit fara sa te observe."<<endl<<endl;
                        }

                        cout<<" Drumul tau continua prin canion, unde se afla un orc furios in cautare de hrana."<<endl;
                        cout<<"1.Lupta"<<endl
                            <<"2.Ocolete zona"<<endl;
                        menuoption = OptionChooseFunc(1,2);
                        if (menuoption==1)
                        {
                            system("cls");
                            warrior.rep=combat(orc.ehp, warrior.dmg, orc.edmg, warrior.def, warrior.hp, warrior.rep);
                            warrior.xp+=30;
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                        }
                        else if (menuoption==2)
                        {
                            system("cls");
                            cout<<" Ai ocolit zona cu succes chiar daca ai pierdut o zi sa faci acest lucru."<<endl<<endl;
                        }

                        cout<<" Exact inainte de a ajunge in capitala, in padurea, te intalnesti cu un aventurier"<<endl
                            <<"care se duela cu un lup puternic."<<endl;
                        cout<<"1.Ajuta"<<endl
                            <<"2.Ignora"<<endl;
                        menuoption = OptionChooseFunc(1,2);
                        if (menuoption==1)
                        {
                            system("cls");
                            warrior.rep=combat(50, warrior.dmg, 10, warrior.def, warrior.hp, warrior.rep);
                            warrior.xp+=40;
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                            cout<<"Aventurier: Multumesc foarte mult, iti sunt recunoscator."<<endl
                                <<warrior.name<<": Mi-a placut sa ma lupt cu un lup asa de puternic."<<endl<<endl;
                        }
                        else if (menuoption==2)
                        {
                            system("cls");
                            cout<<" Ai ignorat aventurierul care se afla in pericol cu mare nerusinare."<<endl<<endl;
                            warrior.rep=warrior.rep-30;
                        }

                        checkpoint++;
check2:

                        cout<<"1.Continue"<<endl
                            <<"2.Hero details"<<endl
                            <<"3.Back to menu"<<endl;
                        menuoption = OptionChooseFunc(1,3);
                        if(menuoption==2)
                        {
                            menuoption=warrior.details(warrior.dmg, warrior.hp, warrior.def, warrior.xp, warrior.lvl, warrior.rep, warrior.name);
                            if (menuoption==0)
                            {
                                system ("cls");
                                goto salvare;
                            }
                            system("cls");
                        }
                        else if(menuoption==3)
                        {
                            system ("cls");
                            goto menu;
                        }
                        else if(menuoption==1)
                        {system("cls");
                            cout<<" Intr-un final ai ajuns la portile capitalei regale. Acolo te intampina un cavaler."<<endl
                                <<"Cavaler: Salutari calatorule, cu ce ocazie ati venit in capitala regala?"<<endl;
cavaler:
                            cout<<"1.Am venit ca sa ma alatur breslei de aventurieri"<<endl
                                <<"2.Lasa-ma in pace!"<<endl
                                <<"3.Cine esti tu?"<<endl;
                            menuoption = OptionChooseFunc(1,3);
                            system("cls");
                            if(menuoption==2)
                            {
                                cout<<warrior.name<<": Lasa-ma in pace!"<<endl
                                    <<"Cavaler: Imi pare rau dar asa ceva nu este posibil, trebuie sa-mi zici ce faci aici,"<<endl
                                    <<"        nu pot lasa pe oricine si oricum sa intre. Deci, ce faci aici?"<<endl;
                                warrior.rep=warrior.rep-10;
                                goto cavaler;
                            }
                            else if(menuoption==3)
                            {
                                cout<<warrior.name<<": Cine esti tu?"<<endl
                                    <<"Cavaler: Oh, eu sunt un mare cavaler al acestui regat care are indatoria de a proteja"<<endl
                                    <<"        portile capitalei regale. Cat despre tine, ce faci aici, la portile capitalei?"<<endl;
                                goto cavaler;
                            }
                            else if(menuoption==1)
                            {
                                warrior.rep+=5;
                                cout<<warrior.name<<": Am venit ca sa ma alatur breslei de aventurieri."<<endl
                                    <<"Cavaler: Oh, foarte bine, breasla este fix in la 100 de metrii in fata de la poarta."<<endl
                                    <<warrior.name<<": Multumesc pentru ajutor."<<endl;
                                cout<<"1.Continua"<<endl;
                                menuoption = OptionChooseFunc(1,1);
                                if(menuoption==1)
                                     system("cls");
                            }
                        cout<<" Ai mers pana la breasla sa ai intrat ca sa te inscrii."<<endl
                            <<"Sofia: Buna, eu sunt Sofia, sefa breslei, cu ce te pot ajuta?"<<endl
                            <<"1.As dori sa ma inscriu in breasla."<<endl
                            <<"2.As dori sa-mi iau o misiune."<<endl;
                        menuoption = OptionChooseFunc(1,2);
                        if(menuoption==1)
                            {
                            system("cls");
                            goto legitimatie;
                            }
                        else if(menuoption==2)
                            {
                            system("cls");
                            cout<<warrior.name<<": As dori sa-mi iau o misiune"<<endl
                                <<"Sofia: Desigur, sa va vad legitimatia."<<endl
                                <<warrior.name<<": Nu am asa ceva."<<endl
                                <<"Sofia: Pentru a lua misiuni trebuie sa aveti o legitimatie de aventurier. Doriti sa va faceti una?"<<endl
                                <<warrior.name<<": Da."<<endl;
legitimatie:
                            cout<<"Sofia: Pentru acest lucru trebuie sa indepliniti o misiune de rang F si una de nivel E. Trebuie sa"
                                <<"      invingi un slime si un lup cenusiu."<<endl
                                <<warrior.name<<": Asta va fi simplu."<<endl
                                <<"Sofia: Ma bucur sa aud, poftim un obiect magic care te ajuta sa vezi statisticile adversarilor in timpul luptei."<<endl
                                <<warrior.name<<": Multumesc."<<endl;
                        checkpoint++;
check3:
                        cout<<"1.Continue"<<endl
                            <<"2.Hero details"<<endl
                            <<"3.Back to menu"<<endl;
                        menuoption = OptionChooseFunc(1,3);
                        if(menuoption==2)
                        {
                            menuoption=warrior.details(warrior.dmg, warrior.hp, warrior.def, warrior.xp, warrior.lvl, warrior.rep, warrior.name);
                            if (menuoption==0)
                            {
                                system ("cls");
                                goto salvare;
                            }
                            system("cls");
                        }
                        else if(menuoption==3)
                        {
                            system ("cls");
                            goto menu;
                        }
                        else if(menuoption==1)
                            {system("cls");
                            cout<<" Dupa ce ai ajuns in padure ai incput sa cauti bestii pana ai dat de un slime de lvl 3."<<endl
                                <<"1.Fight"<<endl;
                            menuoption = OptionChooseFunc(1,1);
                            if(menuoption==1)
                                {system("cls");
                                warrior.rep=combatinfo(slime.ehp*1.3*1.3, warrior.dmg, slime.edmg*1.3*1.3, warrior.def, warrior.hp, warrior.rep, slime.edef);
                                warrior.xp+=20;}
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                            cout<<" Dupa infrangerea acelui slime iti continui drumul prin padure pana dai de un lup cenusiu tot de nivel 3."<<endl
                                <<"1.Fight"<<endl;
                            menuoption = OptionChooseFunc(1,1);
                                if(menuoption==1)
                                {system("cls");
                                warrior.rep=combatinfo(wolf.ehp*1.3*1.3, warrior.dmg, wolf.edmg*1.3*1.3, warrior.def, warrior.hp, warrior.rep, wolf.edef*1.3*1.3);
                                warrior.xp+=30;}
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                            cout<<warrior.name<<": Ce usor a fost sa indeplinesc misiunnile pentru legitimatie."<<endl
                                <<"*fash* *fash*"<<endl
                                <<warrior.name<<": Cine este acolo?"<<endl
                                <<" Atunci iese o banda de banditi din tufisuri si te ataca."<<endl
                                <<"1.Fight"<<endl;
                            menuoption = OptionChooseFunc(1,1);
                                if(menuoption==1)
                                {system("cls");
                                warrior.rep=combatinfo(40, warrior.dmg, 9, warrior.def, warrior.hp, warrior.rep, 4);
                                warrior.xp+=30;}
                            if(warrior.xp>=50)
                            {
                                cout<<endl<<"   LVL UP!"<<endl<<endl;
                                warrior.dmg=warrior.dmgup(warrior.dmg);
                                warrior.def=warrior.defup(warrior.def);
                                warrior.hp=warrior.hpup(warrior.hp);
                                warrior.lvl=warrior.lvlup(warrior.lvl);
                                warrior.xp=warrior.xpup(warrior.xp);
                            }
                            cout<<warrior.name<<": Pff, ce greu a fost sa-i inving, noroc ca am avut artefactul"<<endl
                                <<"       asta magic cu care le-am vazut statisticile si am putut sa le compar cu "<<endl
                                <<"       cele pe care le am."<<endl;
                                checkpoint++;
check4:
                        cout<<"1.Continue"<<endl
                            <<"2.Hero details"<<endl
                            <<"3.Back to menu"<<endl;
                        menuoption = OptionChooseFunc(1,3);
                        if(menuoption==2)
                        {
                            menuoption=warrior.details(warrior.dmg, warrior.hp, warrior.def, warrior.xp, warrior.lvl, warrior.rep, warrior.name);
                            if (menuoption==0)
                            {
                                system ("cls");
                                goto salvare;
                            }
                            system("cls");
                        }
                        else if(menuoption==3)
                        {
                            system ("cls");
                            goto menu;
                        }
                        else if(menuoption==1)
                            {system("cls");
                            cout<<" Dupa aventura ta, ai ajuns la breasla pentru a raporta terminarea cerintelor."<<endl
                                <<"Sofia: Buna, ce mai faci? Ai terminat cerintele pentru a primi legitimatia?"<<endl
                                <<warrior.name<<": Desigur. Ba chiar am si prins o banda de banditi care m-a atacat."<<endl
                                <<"Sofia: Wow, aceasta banda era cautata de catre cavalerii acestei zone, ai facut mai mult decat trebuia."<<endl
                                <<"      Poftim legitimatia de breasla. Oficial poti lua misiuni ale breslei pentru a primi recompense."<<endl;
                            warrior.rep+=30;
                            cout<<warrior.name<<": Super, abea astept sa incep."<<endl;
                            cout<<"( Povestea va continua in urmatoarele update-uri :)) )"<<endl;
                            //de continuat povestea
                            }
                            }
                            }
                        }
                    }
                }
            }
            else if(menuoption==2)
            {
                system("cls");
                goto ngame;
            }
        }
        else if(menuoption==2)
        {
            system("cls");
            cout<<" Do you want to continue?"<<endl
                <<"1.Yes"<<endl
                <<"2.No"<<endl;
            menuoption = OptionChooseFunc(1,2);
            if(menuoption==1)
            {
                system("cls");
salvare:
                switch(checkpoint)
                {
                case 0:
                    goto check0;
                    break;
                case 1:
                    goto check1;
                    break;
                case 2:
                    goto check2;
                    break;
                case 3:
                    goto check3;
                    break;
                case 4:
                    goto check4;
                    break;
                }
            }
            else if(menuoption==2)
            {
                system("cls");
                goto ngame;
            }
        }
        else if(menuoption==0)
        {
            system("cls");
            goto menu;
        }
        break;

    case 2:
        /*Help*/
        system("cls");
        cout << "   Jocul consta in felul urmator:" << endl
             << "-La poveste trebuie sa alegi una din variantele oferite astfel incat sa influentezi" << endl
             << "povestea si sa castigi sau pierzi puncte de reputatie." << endl
             << "-In timpul luptelor vei avea de ales intre 2 tipuri diferite de atac, 'quickattack' si" << endl
             << "'chargeattack'. Lupta se termina cand eroul sau inamicul ajunge la 0 hp. " << endl
             << "-La finalul jocului, in functie de alegerile facute in timpul povestii vei primi un titlu" << endl
             << "-In timpul luptei, cele doua atacuri functioneaza diferit: "<<endl
             << "    'quickattack' - ataci inaintea oponentului cu daune egale cu dmg-ul eroului"<<endl
             << "    'chargeattack' - ataci dupa adversarul tau cu daune egale cu dmg-ul eroului *1.5"<<endl
             << endl;
        cout<<"0.Back"<<endl;
        menuoption = OptionChooseFunc(0,0);
        if (menuoption == 0)
        {
            system("cls");
            goto menu;
        }

    case 0:
        return 0;
    default:
        break;
    }
}
