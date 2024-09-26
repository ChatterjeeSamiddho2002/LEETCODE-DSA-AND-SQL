typedef struct {
    int start;
    int end;
} Event;
typedef struct {
    Event* events;   // Array to store the events
    int size;        // Current number of events
    int capacity;  
} MyCalendar;


MyCalendar* myCalendarCreate() {
        MyCalendar* obj = (MyCalendar*)malloc(sizeof(MyCalendar));
    obj->size = 0;
    obj->capacity = 10;  // Initial capacity for storing 10 events
    obj->events = (Event*)malloc(obj->capacity * sizeof(Event));
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
        // Check if the new event overlaps with any existing event
    for (int i = 0; i < obj->size; i++) {
        if (!(end <= obj->events[i].start || start >= obj->events[i].end)) {
            // If the new event overlaps with the current one, return false
            return false;
        }
}
 if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->events = (Event*)realloc(obj->events, obj->capacity * sizeof(Event));
    }
    
    // Add the new event to the calendar
    obj->events[obj->size].start = start;
    obj->events[obj->size].end = end;
    obj->size++;
    
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj->events);
    free(obj);
    
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/