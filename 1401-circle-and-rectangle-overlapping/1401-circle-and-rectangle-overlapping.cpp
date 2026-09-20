class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int closestX;
        int closestY;

        // Find the closest x-coordinate inside the rectangle
        if (xCenter < x1)
            closestX = x1;
        else if (xCenter > x2)
            closestX = x2;
        else
            closestX = xCenter;

        // Find the closest y-coordinate inside the rectangle
        if (yCenter < y1)
            closestY = y1;
        else if (yCenter > y2)
            closestY = y2;
        else
            closestY = yCenter;

        // Applied Distance formula r^2=(x2-x1)^2-(y2-y1)^2;
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;

        return dx * dx + dy * dy <= radius * radius;   // cool syntax directly equlity cheack
    }
};