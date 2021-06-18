#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

    // ������� ����
	RenderWindow window(VideoMode(1200, 1080), "DOOM 3000");
	Image birdimage; //������� ������ Image (�����������)
	birdimage.loadFromFile("D:/sfml/sfml_tutorial/images/bird.png");//��������� � ���� ����
	birdimage.createMaskFromColor(Color(247, 247, 247));

	Texture birdtexture;//������� ������ Texture (��������)
	birdtexture.loadFromImage(birdimage);//�������� � ���� ������ Image (�����������)

	Sprite birdsprite;//������� ������ Sprite(������)
	birdsprite.setTexture(birdtexture);//������� � ���� ������ Texture (��������)
	birdsprite.setTextureRect(IntRect(0, 20, 275, 215));//�������� ������ ��� ������������� � �����
	birdsprite.setPosition(100, 100);//������ ��������� ���������� ��������� �������

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) birdsprite.move(0, -0.1); 
		if (Keyboard::isKeyPressed(Keyboard::S)) birdsprite.move(0, 0.1);
		if (Keyboard::isKeyPressed(Keyboard::D)) birdsprite.move(0.1, 0);
		if (Keyboard::isKeyPressed(Keyboard::A)) birdsprite.move(-0.1, 0);
		// ������ ���� ����
		window.clear(Color(0, 255, 255));
		// ��������� �����
		window.draw(birdsprite);
		// ��������� ����	
		window.display();
	}

	return 0;
}