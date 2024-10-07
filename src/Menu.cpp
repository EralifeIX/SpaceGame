#include "../include/Menu.h"



Menu::Menu(ObjectConstructor* oc){
    LoadLetters();
    score = 0;
    paused = true;
    OC = oc;
}

void Menu::Update()
{
    DrawScore();
    if(IsPaused())
        DrawText(" Press Esc to Play", {100, 250 });

}

bool Menu::IsPaused(){
    return paused;
}

void Menu::Switch(){
    paused = !paused;
}

void Menu::Return(){
    paused = false;
}

void Menu::LoadLetters()
{
    sf::Texture temp;
    for(int i = 0 ; i < 10; i++)
    {
        std::string fileneame = "../assets/keys/" +  std::to_string(i) + ".png";
        if(!temp.loadFromFile(fileneame))
        {
            std::cerr<<"Cannot load a file from " + fileneame<< std::endl;
        }
        letters.emplace('0' + i,temp);
    }

    for(int i = 0; i < 26; i++ )
    {
        char letter = 'A' + i;
        std::string fileneame = "../assets/keys/" +  std::string(1, letter) + ".png";
        if(!temp.loadFromFile(fileneame))
        {
            std::cerr<<"Cannot load a file from " + fileneame<< std::endl;
        }

        letters.emplace(letter,temp);
    }
    std::string fileneame = "../assets/keys/:.png";
    if(!temp.loadFromFile(fileneame))
    {
        std::cerr<<"Cannot load a file from " + fileneame<< std::endl;
    }
    letters.emplace(':',temp);
}

void Menu::DrawText(std::string text, sf::Vector2u pos)
{
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    int i = 0;
    int k = OC->GetWindow()->GetRenderWindow().getSize().x / 64;

    int width = letters['A'].getSize().x;
    int height = letters['A'].getSize().y;
    float posx;
    float coeficent;
    for(char& c : text)
    {
        if(c == ' ' ){
            i++;
            continue;
        }

        sf::Sprite sprite(letters[c]);
        coeficent = width * i;
        posx = coeficent + pos.x - (width / 2) * i;
        sprite.setPosition( posx, pos.y); //move by x axis

        sprite.setTextureRect(sf::IntRect(0,0, width/2, height ));
        OC->GetWindow()->Draw(sprite);
        i++;
    }
}


void Menu::AddScore()
{
    score++;
}

void Menu::DrawScore()
{
    sf::Vector2u positions = OC->GetWindow()->GetWindowSize();
    DrawText("Score:" + std::to_string(score), {positions.x / 2 + 200, 50});
}





















