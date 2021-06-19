#include <SFML/Graphics.hpp>
#include <vector>
#include "windows.h"
#include<iostream>

using namespace sf;
using namespace std;

int main() {
	Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� ��������/������������� ����������). 
    // ������� ����
	RenderWindow window(VideoMode(1200, 1080), "DOOM 3000");
	Image birdimage; //������� ������ Image (�����������)
	birdimage.loadFromFile("D:/sfml/sfml_tutorial/images/bird.png");//��������� � ���� ����
	birdimage.createMaskFromColor(Color(247, 247, 247));

	Texture birdtexture;//������� ������ Texture (��������)
	birdtexture.loadFromImage(birdimage);//�������� � ���� ������ Image (�����������)

    Sprite birdsprite;//������� ������ Sprite(������)
	birdsprite.setTexture(birdtexture);//������� � ���� ������ Texture (��������)
	birdsprite.setTextureRect(IntRect(35, 40, 240, 195));//�������� ������ ��� �������������
	birdsprite.setPosition(100, 100);//������ ��������� ���������� ��������� �������

	float CurrentFrame = 0;//������ ������� ����
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 800; //�������� ����

		// ������������ ������� ������� � �����
		Event event;
		
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		// ��������
		if (Keyboard::isKeyPressed(Keyboard::D)) { //���� ������ ������� ������� ����� ��� ���� ����� �
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 40, 240, 195)); 
			birdsprite.move(0.1 * time, 0);//���������� ���� �������� ��������� �����
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 290, 240, 195));
			birdsprite.move(0, -0.2 * time);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 540, 240, 195));
			birdsprite.move(0, 0.05 * time);
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			birdsprite.setTextureRect(IntRect(35 + 275 * int(CurrentFrame), 40, 240, 195));
			birdsprite.move(-0.1 * time, 0);
		}
		
	    // ������� �����
		birdsprite.move(0, 0.1 * time);

		// ������ ���� ����
		window.clear(Color(0, 255, 255));
		// ��������� �����
		window.draw(birdsprite);
		// ��������� ����	
		window.display();
	}

	return 0;
}