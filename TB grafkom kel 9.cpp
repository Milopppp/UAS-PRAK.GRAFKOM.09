#include <GL/glut.h>				//FADILAH

float rotateX = 0.0, rotateY = 0.0; // Variabel untuk rotasi
float zoom = -8.0; // Variabel untuk zoom
bool showCarte = true; // Variabel untuk mengontrol apakah garis kartesius ditampilkan


void drawPyramid(float x, float y, float z, float scale) {		//FADILAH
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);

	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);	

    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.71, 0.55);

    // Sisi depan (normal menghadap ke depan)
    glNormal3f(0.0, 0.5, 1.0); // Normal untuk sisi depan
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(-1.5, -1.0, 1.5);
    glVertex3f(1.5, -1.0, 1.5);

    // Sisi kanan (normal menghadap ke kanan)
    glNormal3f(1.0, 0.5, 0.0); // Normal untuk sisi kanan
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(1.5, -1.0, 1.5);
    glVertex3f(1.5, -1.0, -1.5);

    // Sisi belakang (normal menghadap ke belakang)
    glNormal3f(0.0, 0.5, -1.0); // Normal untuk sisi belakang
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(1.5, -1.0, -1.5);
    glVertex3f(-1.5, -1.0, -1.5);

    // Sisi kiri (normal menghadap ke kiri)
    glNormal3f(-1.0, 0.5, 0.0); // Normal untuk sisi kiri
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(-1.5, -1.0, -1.5);
    glVertex3f(-1.5, -1.0, 1.5);

    glEnd();

    // Dasar piramida (normal menghadap ke bawah)
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0); // Normal untuk dasar
    glVertex3f(-1.5, -1.0, 1.5);
    glVertex3f(1.5, -1.0, 1.5);
    glVertex3f(1.5, -1.0, -1.5);
    glVertex3f(-1.5, -1.0, -1.5);
    glEnd();

	glDisable(GL_NORMALIZE);
    glPopMatrix();
}

void drawMatahari(float x, float y, float z, float scale) {			//FADILAH
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    glColor3f(1.0, 0.84, 0.0); // Warna kuning untuk matahari
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
}

void drawBatu(float x, float y, float z, float scale) {				//KAMILA
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    glColor3f(0.5, 0.5, 0.5); // Warna abu-abu gelap untuk batu
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}

void drawPohon(float x, float y, float z) {						//KAMILA
    glPushMatrix();
    glTranslatef(x, y, z);

    // Batang pohon (lebih kecil)
    glColor3f(0.55, 0.27, 0.07); // Warna coklat untuk batang
    glBegin(GL_QUADS);
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(0.05, 0.0, -0.05);
    glVertex3f(0.05, 1.0, -0.05); // Tinggi batang menjadi 1.0
    glVertex3f(-0.05, 1.0, -0.05);

    glVertex3f(-0.05, 0.0, 0.05);
    glVertex3f(0.05, 0.0, 0.05);
    glVertex3f(0.05, 1.0, 0.05);
    glVertex3f(-0.05, 1.0, 0.05);

    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 0.0, 0.05);
    glVertex3f(-0.05, 1.0, 0.05);
    glVertex3f(-0.05, 1.0, -0.05);

    glVertex3f(0.05, 0.0, -0.05);
    glVertex3f(0.05, 0.0, 0.05);
    glVertex3f(0.05, 1.0, 0.05);
    glVertex3f(0.05, 1.0, -0.05);
    glEnd();

    // Daun kelapa (posisi dan dimensi disesuaikan)
    glColor3f(0.0, 0.5, 0.0); // Warna hijau untuk daun
    glBegin(GL_TRIANGLES);

    // Daun pertama (kiri depan)
    glVertex3f(0.0, 1.0, 0.0); // Dasar daun tepat di ujung batang
    glVertex3f(-0.7, 1.2, -0.3); // Ujung daun lebih panjang
    glVertex3f(-0.4, 1.2, -0.6);

    // Daun kedua (kanan depan)
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.7, 1.2, -0.3);
    glVertex3f(0.4, 1.2, -0.6);

    // Daun ketiga (kiri belakang)
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-0.7, 1.2, 0.3);
    glVertex3f(-0.4, 1.2, 0.6);

    // Daun keempat (kanan belakang)
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.7, 1.2, 0.3);
    glVertex3f(0.4, 1.2, 0.6);

    glEnd();

    glPopMatrix();
}

void drawLantai() {						//FADILAH
    glPushMatrix();

    glColor3f(0.96, 0.87, 0.70); // Warna krem untuk lantai

    // Gambarkan lantai dengan normal untuk setiap sisi
    glBegin(GL_QUADS);

    // Sisi atas (normal menghadap ke atas)
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-5.0, -1.0, 5.0);
    glVertex3f(5.0, -1.0, 5.0);
    glVertex3f(5.0, -1.0, -5.0);
    glVertex3f(-5.0, -1.0, -5.0);

    // Sisi bawah (normal menghadap ke bawah)
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-5.0, -1.5, 5.0);
    glVertex3f(5.0, -1.5, 5.0);
    glVertex3f(5.0, -1.5, -5.0);
    glVertex3f(-5.0, -1.5, -5.0);

    // Sisi depan (normal menghadap ke depan)
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-5.0, -1.0, 5.0);
    glVertex3f(5.0, -1.0, 5.0);
    glVertex3f(5.0, -1.5, 5.0);
    glVertex3f(-5.0, -1.5, 5.0);

    // Sisi belakang (normal menghadap ke belakang)
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(-5.0, -1.0, -5.0);
    glVertex3f(5.0, -1.0, -5.0);
    glVertex3f(5.0, -1.5, -5.0);
    glVertex3f(-5.0, -1.5, -5.0);

    // Sisi kiri (normal menghadap ke kiri)
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-5.0, -1.0, 5.0);
    glVertex3f(-5.0, -1.0, -5.0);
    glVertex3f(-5.0, -1.5, -5.0);
    glVertex3f(-5.0, -1.5, 5.0);

    // Sisi kanan (normal menghadap ke kanan)
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(5.0, -1.0, 5.0);
    glVertex3f(5.0, -1.0, -5.0);
    glVertex3f(5.0, -1.5, -5.0);
    glVertex3f(5.0, -1.5, 5.0);

    glEnd();

    glPopMatrix();
}

void drawBackSky() {		//KAMILA
    glPushMatrix();

    glBegin(GL_QUADS);

    // Sisi belakang (menghadap kamera)
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(-5.0, -1.5, -6.0); // Kiri bawah
    glVertex3f(5.0, -1.5, -6.0);  // Kanan bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(5.0, 3.0, -6.0);   // Kanan atas
    glVertex3f(-5.0, 3.0, -6.0);  // Kiri atas

    // Sisi depan
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-5.0, -1.5, -5.0); // Kiri bawah
    glVertex3f(5.0, -1.5, -5.0);  // Kanan bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(5.0, 3.0, -5.0);   // Kanan atas
    glVertex3f(-5.0, 3.0, -5.0);  // Kiri atas

    // Sisi kiri
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-5.0, -1.5, -5.0); // Depan bawah
    glVertex3f(-5.0, -1.5, -6.0); // Belakang bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(-5.0, 3.0, -6.0);  // Belakang atas
    glVertex3f(-5.0, 3.0, -5.0);  // Depan atas

    // Sisi kanan
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(5.0, -1.5, -5.0); // Depan bawah
    glVertex3f(5.0, -1.5, -6.0); // Belakang bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(5.0, 3.0, -6.0);  // Belakang atas
    glVertex3f(5.0, 3.0, -5.0);  // Depan atas

    // Sisi bawah
    glColor3f(0.96, 0.87, 0.70); // Warna krem
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-5.0, -1.5, -5.0); // Depan kiri
    glVertex3f(5.0, -1.5, -5.0);  // Depan kanan
    glVertex3f(5.0, -1.5, -6.0);  // Belakang kanan
    glVertex3f(-5.0, -1.5, -6.0); // Belakang kiri

    // Sisi atas
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-5.0, 3.0, -5.0);  // Depan kiri
    glVertex3f(5.0, 3.0, -5.0);   // Depan kanan
    glVertex3f(5.0, 3.0, -6.0);   // Belakang kanan
    glVertex3f(-5.0, 3.0, -6.0);  // Belakang kiri

    glEnd();

    glPopMatrix();
}

void drawRightSky() {			//IMAM
    glPushMatrix();

    glBegin(GL_QUADS);

    // Sisi kanan
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(5.0, -1.5, -5.0); // Bawah belakang
    glVertex3f(5.0, -1.5, 5.0);  // Bawah depan
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(5.0, 3.0, 5.0);   // Atas depan
    glVertex3f(5.0, 3.0, -5.0);  // Atas belakang

    // Sisi kiri
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(6.0, -1.5, -5.0); // Bawah belakang
    glVertex3f(6.0, -1.5, 5.0);  // Bawah depan
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(6.0, 3.0, 5.0);   // Atas depan
    glVertex3f(6.0, 3.0, -5.0);  // Atas belakang

    // Sisi depan
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(5.0, -1.5, 5.0);  // Kanan bawah
    glVertex3f(6.0, -1.5, 5.0);  // Kiri bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(6.0, 3.0, 5.0);   // Kiri atas
    glVertex3f(5.0, 3.0, 5.0);   // Kanan atas

    // Sisi belakang
    glColor3f(0.96, 0.87, 0.70); // Warna krem (bawah)
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(5.0, -1.5, -5.0); // Kanan bawah
    glVertex3f(6.0, -1.5, -5.0); // Kiri bawah
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda (atas)
    glVertex3f(6.0, 3.0, -5.0);  // Kiri atas
    glVertex3f(5.0, 3.0, -5.0);  // Kanan atas

    // Sisi bawah
    glColor3f(0.96, 0.87, 0.70); // Warna krem
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(5.0, -1.5, -5.0); // Belakang kanan
    glVertex3f(6.0, -1.5, -5.0); // Belakang kiri
    glVertex3f(6.0, -1.5, 5.0);  // Depan kiri
    glVertex3f(5.0, -1.5, 5.0);  // Depan kanan

    // Sisi atas
    glColor3f(0.53, 0.81, 0.98); // Warna biru muda
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(5.0, 3.0, -5.0);  // Belakang kanan
    glVertex3f(6.0, 3.0, -5.0);  // Belakang kiri
    glVertex3f(6.0, 3.0, 5.0);   // Depan kiri
    glVertex3f(5.0, 3.0, 5.0);   // Depan kanan

    glEnd();

    glPopMatrix();
}


void drawCarte() {			//IMAM
    if (!showCarte) return; // Tidak menggambar jika showAxis false

    glPushMatrix();

    // Sumbu X (merah)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glEnd();

    // Sumbu Y (hijau)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -50.0, 0.0);
    glVertex3f(0.0, 50.0, 0.0);
    glEnd();

    // Sumbu Z (biru)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -50.0);
    glVertex3f(0.0, 0.0, 50.0);
    glEnd();

    glPopMatrix();
}

void display() {			//FADILAH
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    
    glLoadIdentity();

    glTranslatef(0.0, 0.0, zoom); // Pindahkan kamera untuk zoom
    glRotatef(rotateX, 1.0, 0.0, 0.0); // Rotasi pada sumbu X
    glRotatef(rotateY, 0.0, 1.0, 0.0); // Rotasi pada sumbu Y

    drawCarte(); // Gambar garis kartesius (tergantung showAxis)

    drawLantai(); // Gambar lantai
    drawBackSky();
    drawRightSky();
    
    drawMatahari(4.0, 2.0, -3.0, 1.0);

    // Gambar tiga piramida
    drawPyramid(-2.5, -0.5, 0.0, 0.5); // Piramida kiri lebih kecil dan lebih bawah
    drawPyramid(0.0, 0.0, 0.0, 1.0);   // Piramida tengah normal
    drawPyramid(2.5, -0.5, 0.0, 0.5);  // Piramida kanan lebih kecil dan lebih bawah

    // Gambar pohon kelapa
    drawPohon(-4.0, -1.0, -2.0);
    drawPohon(4.0, -1.0, -2.0);

    // Gambar batu-batu
    drawBatu(-1.5, -1.0, 2.0, 0.5);
    drawBatu(1.0, -1.0, -2.5, 0.3);
    drawBatu(3.0, -1.0, 1.5, 0.7);

    glutSwapBuffers();
   
}

void reshape(int w, int h) {		//KAMILA
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y) {		//KAMILA
    switch (key) {
        case 'w': // Rotasi ke atas
            rotateX -= 5.0;
            break;
        case 's': // Rotasi ke bawah
            rotateX += 5.0;
            break;
        case 'a': // Rotasi ke kiri
            rotateY -= 5.0;
            break;
        case 'd': // Rotasi ke kanan
            rotateY += 5.0;
            break;
        case 'i': // Zoom in
            zoom += 0.5;
            break;
        case 'o': // Zoom out
            zoom -= 0.5;
            break;
        case 'x': // Toggle garis kartesius
            showCarte = !showCarte;
            break;
    }
    glutPostRedisplay(); // Refresh tampilan
}

void MenuKeluar(int option) {		//KAMILA
    switch (option) {
        case 0: // Opsi keluar
            exit(0);
            break;
    }
}

// Fungsi untuk membuat menu klik kanan
void createMenu() {				//KAMILA
    glutCreateMenu(MenuKeluar);
    glutAddMenuEntry("Keluar", 0); // Tambahkan entri menu "Keluar"
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Kaitkan menu dengan klik kanan
}

void init() {			//IMAM
	
    glEnable(GL_DEPTH_TEST);           // Aktifkan depth test
    glEnable(GL_COLOR_MATERIAL); 
    glEnable(GL_LIGHT0); // Sumber cahaya 0
    
    glClearColor(0.0, 0.0, 0.0, 1.0); // Warna latar belakang hitam

    // Atur parameter sumber cahaya
	GLfloat lightPosition[] = {6.0, 3.0, -6.0, 1.0}; // Posisi sumber cahaya
    GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1.0};  // Cahaya sekitar
    GLfloat lightDiffuse[] = {1.0, 1.0, 1.0, 1.0};  // Cahaya difus
    GLfloat lightSpecular[] = {1.0, 1.0, 1.0, 1.0}; // Cahaya spesular

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}

int main(int argc, char** argv) {		//IMAM
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Piramida 3D");

    init();
    
    createMenu();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // Fungsi untuk input keyboard

    glutMainLoop();
    return 0;
}
