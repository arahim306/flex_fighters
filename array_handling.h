#ifndef ARRAY_HANDLING_H
#define ARRAY_HANDLING_H

#include "sam.h"
#include <string.h>
#define circBufSize 256

typedef struct circularBuf {
	uint32_t buf[circBufSize];
	int head;
	int tail;
	int count;
	uint32_t sum;
} circularBuf;

// circBufInit - creates new circular buffer
void circBufInit (circularBuf *_this) {
	// clear buf, head, tail, count, and set head = tail
	memset (_this, (uint32_t)0, sizeof(*_this));
}

// circBufEmpty - returns true if the buffer is empty
int circBufEmpty (circularBuf *_this) {
	return (0==_this->count);
}

// circBufFull - returns true if the buffer is full
int circBufFull (circularBuf *_this) {
	return (_this->count>=circBufSize);
}

// circBufGet - returns value of buffer at tail index and
//              increments tail; wraps tail back to beginning of
//              buffer if tail increments beyond the buffer size
uint32_t circBufGet (circularBuf *_this) {
	uint32_t g;
	if (_this->count>0) {
		g = _this->buf[_this->tail];
		_this->tail = _this->tail+1;
		if (_this->tail >= circBufSize) {
			_this->tail = 0;
		}
	}
	// return a bogus value if the buffer is empty
	else {
		g = -1;
	}
	return g;
}

// circBufPut - places a new value at the head of the buffer
//              and adds the value to the buffer's running sum;
//              if it overwrites an old value, also subtracts
//              the old value from the sum of the buffer
void circBufPut (circularBuf *_this, const uint32_t p) {
	if (_this->head < circBufSize) {
		_this->sum -= _this->buf[_this->head];
	}
	_this->sum += p;
	_this->buf[_this->head] = p;
	_this->head = _this->head+1;
	if (_this->head >= circBufSize) {
		_this->head = 0;
	}
	if (_this->count < circBufSize) {
		++_this->count;
	}
}

// circBufFlush - resets existing buffer to being empty
void circBufFlush (circularBuf *_this, const int clearBuffer) {
	_this->count = 0;
	_this->head = 0;
	_this->tail = 0;
	_this->sum = 0;
	if (clearBuffer) {
		memset (_this->buf, (uint32_t)0, sizeof(_this->buf));
	}
}

// getSum - returns running sum of circular buffer
uint32_t getSum(circularBuf *_this) {
	return _this->sum;
}

// peakDetection - detects peaks in signal using the sum of the
//                 circular buffer, and triggers a punch if a 
//                 peak is detected above a certain threshold
void peakDetection(circularBuf *_this, uint32_t *max, uint32_t threshold, int *trigger) {
	uint32_t curSum = getSum(_this);
	// keep increasing max sum of the buffer as it is being overwritten
	if (curSum > *max) {
		*max = curSum;
	}
	// if the sum has dropped substantially, the sum is dropping from
	// a peak, so trigger a punch on that channel
	else if (*max > threshold && curSum < *max * 0.6) {
		*trigger = 1;
	}
}

#endif