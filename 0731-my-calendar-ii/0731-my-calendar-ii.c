typedef struct {
    int start;
    int end;
} Event;

typedef struct {
    Event* booked;   // List of booked events (single bookings)
    Event* overlaps; // List of double bookings (overlaps of two bookings)
    int bookedSize;  // Number of booked events
    int overlapsSize; // Number of overlaps
    int bookedCapacity; // Capacity of booked array
    int overlapsCapacity; // Capacity of overlaps array
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->bookedSize = 0;
    obj->overlapsSize = 0;
    obj->bookedCapacity = 10;   // Initial capacity
    obj->overlapsCapacity = 10; // Initial capacity
    obj->booked = (Event*)malloc(obj->bookedCapacity * sizeof(Event));
    obj->overlaps = (Event*)malloc(obj->overlapsCapacity * sizeof(Event));
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // Check if the new event overlaps with any double-booked intervals
    for (int i = 0; i < obj->overlapsSize; i++) {
        int oStart = obj->overlaps[i].start;
        int oEnd = obj->overlaps[i].end;
        if (start < oEnd && end > oStart) {
            // This would cause a triple booking, so return false
            return false;
        }
    }
    
    // Check for overlaps with existing single bookings
    for (int i = 0; i < obj->bookedSize; i++) {
        int bStart = obj->booked[i].start;
        int bEnd = obj->booked[i].end;
        if (start < bEnd && end > bStart) {
            // Calculate the overlap
            int overlapStart = (start > bStart) ? start : bStart;
            int overlapEnd = (end < bEnd) ? end : bEnd;
            
            // Add the overlap to the overlaps list
            if (obj->overlapsSize == obj->overlapsCapacity) {
                obj->overlapsCapacity *= 2;
                obj->overlaps = (Event*)realloc(obj->overlaps, obj->overlapsCapacity * sizeof(Event));
            }
            obj->overlaps[obj->overlapsSize].start = overlapStart;
            obj->overlaps[obj->overlapsSize].end = overlapEnd;
            obj->overlapsSize++;
        }
    }
    
    // Add the new event to the booked list
    if (obj->bookedSize == obj->bookedCapacity) {
        obj->bookedCapacity *= 2;
        obj->booked = (Event*)realloc(obj->booked, obj->bookedCapacity * sizeof(Event));
    }
    obj->booked[obj->bookedSize].start = start;
    obj->booked[obj->bookedSize].end = end;
    obj->bookedSize++;
    
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->booked);
    free(obj->overlaps);
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 * myCalendarTwoFree(obj);
 */


