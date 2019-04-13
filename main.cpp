#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <stdlib.h>
#include <iostream>
const unsigned int C_WIDTH = 5;
const unsigned int C_HEIGHT = 5;

using ::std::vector;

void draw(vector<unsigned int>& numbers , int  current_el ,  const unsigned int W_H , sf::RenderWindow &wn);

/*

void bubble_sort(vector<unsigned int>& numbers , const unsigned int W_H , sf::RenderWindow &wn)
{
    bool sorted = false;
    int i = 0;
    while (not sorted and i < numbers.size()-1)
    {
        draw(numbers ,numbers[i],W_H ,wn);
        sorted = true;
        int a = i;
        while (a < numbers.size()-1){
        if(numbers[a] < numbers[a] + 1 )
            {
            std::swap(numbers[a],numbers[a+1]);
            draw(numbers ,numbers[a+1],W_H ,wn);
            sorted = false;
            }
            ++a;
        }
        ++i;
    }

}

*/

void bubble_sort(vector<unsigned int>& numbers , const unsigned int W_H , sf::RenderWindow &wn)
{
    for( int i = 0; i < numbers.size(); i++ )
    {

        std::cout<<"Hello";
        for( int j = 0; j < numbers.size() - 1; j++ )
        {
            draw(numbers ,j,W_H ,wn);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if( numbers[ j ] > numbers[ j + 1 ] )

                std::swap( numbers[ j ], numbers[ j + 1 ] );
                draw(numbers ,(j+1),W_H ,wn);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
}

int main()
{

    srand (time(NULL));
    vector<unsigned int>vec {10,3,4,5 , 20 , 1 , 3 ,10,3};
    for (int i = 0 ; i < 100; ++i)
    {
        vec.emplace_back(rand() % 100 + 10);
    }


    unsigned int max = *max_element(vec.begin(),vec.end());
    const unsigned int W_H =  max * C_HEIGHT + 100;
    sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(vec.size() * C_WIDTH),W_H), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    bool running = true;
    while (running)
    {

        bubble_sort(vec , W_H , window);
        break;
        draw(vec,vec[2],W_H ,window);
        /*window.clear();
        window.draw(shape);
        window.display();*/
    }
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    return 0;
}

void draw(vector<unsigned int>& numbers ,  int  current_el ,  const unsigned int W_H, sf::RenderWindow &wn)
{
    wn.clear();
    for(int i = 0 ; i < numbers.size() ; ++i)
    {
        sf::RectangleShape rectangle(sf::Vector2f(C_WIDTH, numbers[i] * C_HEIGHT));
        rectangle.setPosition(i * C_WIDTH  , W_H - numbers[i] * C_HEIGHT );
        if(i==current_el)
        {
            rectangle.setFillColor(sf::Color(150,50,250));
        }
        wn.draw(rectangle);
    }
    wn.display();
};

