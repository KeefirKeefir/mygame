#include "hitboxes.hpp" 

bool checkCollisionRectHBLine(RectHB& rect, const Line& line) {
    vec points[4] = {
        {rect.pos.x, rect.pos.y}, 
        {rect.pos.x + rect.dims.x, rect.pos.y}, 
        {rect.pos.x, rect.pos.y + rect.dims.y}, 
        {rect.pos.x + rect.dims.x, rect.pos.y + rect.dims.y}
    };
    if (CheckCollisionPointRec(line.p1, rect.makeRect()) || CheckCollisionPointRec(line.p2, rect.makeRect())) {
        return true;
    }
    for (u32 i = 0; i < 4; i ++) {
        u32 j = i + 1;
        if (i == 3) {
            j = 0;
        }

        Line line2 {points[i], points[j]};
        vec* collPoint = nullptr;
        if (CheckCollisionLines(line.p1, line.p2, line2.p1, line2.p2, collPoint)) {
            return true;
        }
        free(collPoint);
    }
    return false;
}


Rectangle RectHB::makeRect() {
    return Rectangle{pos.x, pos.y, dims.x, dims.y};
}

bool CircleHB::check(CircleHB& circle) {
	return CheckCollisionCircles(pos, r, circle.pos, circle.r);
}

bool CircleHB::check(RectHB& rect) {
    return CheckCollisionCircleRec(pos, r, rect.makeRect());
}

bool CircleHB::check(const Line& line) {
    return CheckCollisionCircleLine(pos, r, line.p1, line.p2);
}

bool CircleHB::check(vec& point) {
    return CheckCollisionPointCircle(point, pos, r);
}

// ---- RectHB ----

bool RectHB::check(RectHB& rect) {
    return CheckCollisionRecs(makeRect(), rect.makeRect());
}

bool RectHB::check(CircleHB& circle) {
    return CheckCollisionCircleRec(circle.pos, circle.r, makeRect());
}

bool RectHB::check(const Line& line) {
    return checkCollisionRectHBLine(*this, line);
}

bool RectHB::check(vec& point) {
    return CheckCollisionPointRec(point, makeRect());
}
