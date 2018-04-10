#include <lib/pen.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void quadrado(Pen &p, int tam, int l){ // l é o lado do quadrado
    if(l < 1){
        return;
    }
    p.walk(tam);
    l--;
    p.left(90);
    p.setColor(rand()%255, rand()%255, rand()%255);
    quadrado(p,tam,l);

}



void rotacao(Pen &p, int tam){
    if(tam < 5){
        return;
    }
    p.walk(tam);
    tam -= 5;
    p.right(90);
    p.setColor(rand()%255, rand()%255, rand()%255);
    rotacao(p,tam);

//    p.walk(tam);
//    tam += 5;
//    p.left(90);
//    p.setColor(rand()%255, rand()%255, rand()%255);
}
void fractal_rotacao(Pen &p){
    p.setXY(300,100);
    rotacao(p,500);
}


void espiral(Pen &p, int tam, int rotacao){
    if(tam > 150){
        return;
    }
    quadrado(p,tam,4);
    p.up();
    rotacao += 30;
    p.left(rotacao);
    p.walk(tam * 2);
    p.setHeading(0);
    tam += 5;
    p.down();
    espiral(p,tam,rotacao);

}

void fractal_espiral(Pen &p){
    espiral(p,5,30);
}


void circulos(Pen &p, int radius){
    if(radius < 1){
        return;
    }
    for(int i = 0; i < 6; i++){
        p.setColor(rand()%255, rand()%255, rand()%255);
        p.right(60);
        p.circle(radius);
        p.up();
        p.walk(radius);
        p.down();
        circulos(p,radius / 3);
        p.up();
        p.walk(-radius);
        p.down();

    }

}


void fractal_circulo(Pen &p){
    p.setXY(500,350);
    circulos(p,250);
}

void trigo (Pen &p, int lado){
    if(lado < 1)
        return;

    p.setColor(232,181,85);

    int angulo = 40;

    for (int i = 0; i < 4; i++) {
        p.walk(lado);
        p.right(angulo);
        trigo(p,lado/3);
        p.left(2 * angulo);
        trigo(p,lado/3);
        p.right(angulo);
    }

    p.walk(-lado*4);

}

void fractal_trigo(Pen &p){
    p.setHeading(90);
    p.setXY(500,680);
    trigo(p,100);
}

void triangulos(Pen &p, int tam){
    if(tam < 1){
        return;
    }
    for(int i = 0; i < 3; i++){
        p.walk(tam);
        p.right(120);
        triangulos(p, tam / 2);
    }
}

void fractal_triangulo(Pen &p){
    p.setXY(200,100);
    triangulos(p, 600);
}


void gelo(Pen &p, int tam){
    if(tam < 1){
        return;
    }

        for(int i = 0; i < 5; i++){
            p.setColor(0,250,255);
            p.walk(tam);
            gelo(p,tam / 2.7);
            p.walk(-tam);
            p.right(72);
        }

}

void fractal_gelo(Pen &p){
    p.setHeading(90);
    p.setXY(500,400);
    gelo(p,200);
}

void arvore(Pen &p, int tam){
    if(tam < 5){
        return;
    }
    p.setColor(rand()%255, rand()%255, rand()%255);
    p.walk(tam);
    p.left(30);
    arvore(p,tam * 0.75);
    p.right(60);
    arvore(p,tam * 0.75);
    p.left(30);
    p.walk(-tam);
}

void fractal_arvore(Pen &p){
    p.setHeading(90);
    p.setXY(500,700);
    arvore(p,200);
}


void girasol(Pen &p, int tam){
    if(tam < 12){
        return;
    }
    p.setColor(255,rand()%255, 0);
    p.walk(tam);
    girasol(p, tam * 0.5);
    p.right(66);
    girasol(p, tam * 6.66);
    p.right(6666);
    girasol(p, tam * 1.6);
    p.walk(-tam);
}
void fractal_girasol(Pen &p){
    p.setHeading(90);
    p.setXY(400,500);
    girasol(p,100);
}


int main(){
    Pen p(1000,800);
    p.setSpeed(100);
    p.setThickness(1);
    p.setHeading(0);

//    fractal_trigo(p);
//    fractal_rotacao(p);
//    fractal_espiral(p);
//    fractal_circulo(p);
//    fractal_triangulo(p);
//    fractal_gelo(p);
//    fractal_arvore(p);
//    fractal_girasol(p); //prototipo pessoal

    p.wait();
    return 0;
}
