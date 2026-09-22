class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest point on the rectangle
        // to the center of the circle
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate squared distance
        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;

        long long distanceSquared = dx * dx + dy * dy;

        // Circle and rectangle overlap if
        // closest point lies inside/on the circle
        return distanceSquared <= 1LL * radius * radius;
    }
};