#include <SFML/Graphics.hpp>
#include <vector>
#include "windows.h"
#include<iostream>

using namespace sf;
using namespace std;

int main() {
	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 
    // Создаем окно
	RenderWindow window(VideoMode(1200, 1080), "DOOM 3000");
	Image birdimage; //создаем объект Image (изображение)
	birdimage.loadFromFile("D:/sfml/sfml_tutorial/images/bird.png");//загружаем в него файл
	birdimage.createMaskFromColor(Color(247, 247, 247));

	Texture birdtexture;//создаем объект Texture (текстура)
	birdtexture.loadFromImage(birdimage);//передаем в него объект Image (изображения)

    Sprite birdsprite;//создаем объект Sprite(спрайт)
	birdsprite.setTexture(birdtexture);//передаём в него объект Texture (текстуры)
	birdsprite.setTextureRect(IntRect(35, 40, 240, 195));//получили нужный нам прямоугольник
	birdsprite.setPosition(100, 100);//задаем начальные координаты появления спрайта

	float CurrentFrame = 0;//хранит текущий кадр
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры

		// Обрабатываем очередь событий в цикле
		Event event;
		
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		// Кнопочки
		if (Keyboard::isKeyPressed(Keyboard::D)) { //если нажата клавиша стрелка влево или англ буква А
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 40, 240, 195)); 
			birdsprite.move(0.1 * time, 0);//происходит само движение персонажа влево
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 290, 240, 195));
			birdsprite.move(0, -0.2 * time);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 540, 240, 195));
			birdsprite.move(0, 0.05 * time);
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 40, 240, 195));
			birdsprite.move(-0.1 * time, 0);
		}
		
	    // Падение птицы
		birdsprite.move(0, 0.1 * time);

		// Задаем цвет фона
		window.clear(Color(0, 255, 255));
		// Отрисовка круга
		window.draw(birdsprite);
		// Отрисовка окна	
		window.display();
	}

	return 0;
}