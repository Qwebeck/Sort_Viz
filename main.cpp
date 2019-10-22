#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>         
#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <exception>

const unsigned int C_WIDTH = 5;
const unsigned int C_HEIGHT = 5;

using ::std::vector;

class ProgrammTerminated: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Program End";
  }
} terminated;


void check_for_exit(sf::Event& event, sf::RenderWindow& window){
   
    window.pollEvent(event);
    if (event.type == sf::Event::Closed)
        {
            window.close();
            throw terminated;
            
        }
}


void draw(vector<unsigned int>& numbers ,
           std::pair<int,int>  draw_els,
          const unsigned int W_H ,
          sf::RenderWindow &wn,
          sf::Color color = sf::Color(150,50,250), 
          bool clear = true);



void bubble_sort(vector<unsigned int>& numbers , const unsigned int W_H ,sf::Event& event, sf::RenderWindow &wn)
{

    std::pair<int,int> elements= std::make_pair<int,int>(-1,-1); // -1 - uninitialized values
    for( int i = 0; i < numbers.size(); i++ )
    {
        for( int j = 0; j < numbers.size() - 1; j++ )
        { 
            check_for_exit(event,wn);
            elements.first = j;
            draw(numbers ,elements,W_H ,wn);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if( numbers[ j ] > numbers[ j + 1 ] )
                elements.first = j+1;
                std::swap( numbers[ j ], numbers[ j + 1 ] );
                draw(numbers ,elements,W_H ,wn);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
}

  
void selectionSort(vector<unsigned int>& numbers , const unsigned int W_H , sf::Event& event, sf::RenderWindow &wn)  
{  
    
    int i, j, min_idx;  
    int n = numbers.size();
    // -1 means uninitialize positions
    std::pair<int,int> elements = std::make_pair<int,int>(-1,-1);
    for (i = 0; i < n-1; i++)  
    {  
        
        min_idx = i;  
        elements.first = i;
        for (j = i+1; j < n; j++)  
        check_for_exit(event,wn);
        if (numbers[j] < numbers[min_idx]) 
           
            min_idx = j; 
            elements.second = min_idx;
            draw(numbers,elements,W_H,wn);           
            std::swap(numbers[min_idx], numbers[i]); 
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
             
            
    }  
}  


int main()
{

    srand (time(NULL));
    vector<unsigned int>vec {10,3,4,5 , 20 , 1 , 3 ,10,3};
    sf::Event event;
    for (int i = 0 ; i < 100; ++i)
    {
        vec.emplace_back(rand() % 100 + 10);
    }


    unsigned int max = *max_element(vec.begin(),vec.end());
    const unsigned int W_H =  max * C_HEIGHT + 100;
    sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(vec.size() * C_WIDTH),W_H), "Vizualiztion of sorting alghoritms");
  
    bool running = true;
    
    while (running)
    { 
        
        try
        {
            selectionSort(vec , W_H , event, window);
        }
        catch(const std::exception& e)
        {
            running = false;
            std::cerr << e.what() << '\n';
        }
        
        
        
        
        
    }
    
 

    return 0;
}

void draw(vector<unsigned int>& numbers ,  std::pair<int,int>  draw_els ,  const unsigned int W_H, sf::RenderWindow &wn,sf::Color color, bool clear)
{
    if(clear) wn.clear();
    for(int i = 0 ; i < numbers.size() ; ++i)
    {
        sf::RectangleShape rectangle(sf::Vector2f(C_WIDTH, numbers[i] * C_HEIGHT));
        rectangle.setPosition(i * C_WIDTH  , W_H - numbers[i] * C_HEIGHT );
        
        if(i==draw_els.first || i==draw_els.second ) rectangle.setFillColor(color);
        
        
        wn.draw(rectangle);
    }
    wn.display();
};

