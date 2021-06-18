#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

    // Создаем окно
	RenderWindow window(VideoMode(1200, 1080), "DOOM 3000");
	Image birdimage; //создаем объект Image (изображение)
	birdimage.loadFromFile("D:/sfml/sfml_tutorial/images/bird.png");//загружаем в него файл
	birdimage.createMaskFromColor(Color(247, 247, 247));

	Texture birdtexture;//создаем объект Texture (текстура)
	birdtexture.loadFromImage(birdimage);//передаем в него объект Image (изображения)

	Sprite birdsprite;//создаем объект Sprite(спрайт)
	birdsprite.setTexture(birdtexture);//передаём в него объект Texture (текстуры)
	birdsprite.setTextureRect(IntRect(0, 20, 275, 215));//получили нужный нам прямоугольник с котом
	birdsprite.setPosition(100, 100);//задаем начальные координаты появления спрайта

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) birdsprite.move(0, -0.1); 
		if (Keyboard::isKeyPressed(Keyboard::S)) birdsprite.move(0, 0.1);
		if (Keyboard::isKeyPressed(Keyboard::D)) birdsprite.move(0.1, 0);
		if (Keyboard::isKeyPressed(Keyboard::A)) birdsprite.move(-0.1, 0);
		// Задаем цвет фона
		window.clear(Color(0, 255, 255));
		// Отрисовка круга
		window.draw(birdsprite);
		// Отрисовка окна	
		window.display();
	}

	return 0;
}