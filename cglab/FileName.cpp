#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<windows.h>

using namespace std;
GLfloat x1, x2, y_1, y2;

void Draw()
{

    GLfloat M, p, dx, dy, x, y, t;
    glClear(GL_COLOR_BUFFER_BIT);

    if ((x2 - x1) == 0)
        M = (y2 - y_1);
    else
        M = (y2 - y_1) / (x2 - x1);

    if (fabs(M) < 1)
    {
        if (x1 > x2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y_1;
            y_1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y_1);

        p = 2 * dy - dx;

        x = x1;
        y = y_1;

        glBegin(GL_POINTS);
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;

            if (p >= 0)
            {
                y = y + 1;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                y = y;
                p = p + 2 * dy;
            }
        }
        glEnd();
    }

    if (fabs(M) >= 1)
    {
        if (y_1 > y2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y_1;
            y_1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y_1);

        p = 2 * dx - dy;

        x = x1;
        y = y_1;

        glBegin(GL_POINTS);
        while (y <= y2)
        {
            glVertex2f(x, y);
            y = y + 1;

            if (p >= 0)
            {
                x = x + 1;
                p = p + 2 * dx - 2 * dy;
            }
            else
            {
                x = x;
                p = p + 2 * dx;
            }
        }
        glEnd();
    }

    glFlush();
}



void Init() {
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}
int main(int argc, char** argv) {
    cout << "Enter point(x1,y_1):";
    cin >> x1 >> y_1;
    cout << "Enter point(x2,y2):";
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Brenham's Line");
    glutDisplayFunc(Draw);
    Init();
    glutMainLoop();
    return 0;
}

