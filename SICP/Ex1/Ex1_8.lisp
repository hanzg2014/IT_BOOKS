(define (square x) (* x x))

(define (cubic x) (* x x x))

(define (improve guess x)
	(/ (+ (/ x (square guess)) (* 2 guess)) 3))

(define TOLERENCE 0.001)

(define (good-enough? guess x)
	(< (abs (- (cubic guess) x)) TOLERENCE)
	)

(define (cubic-iter guess x)
	(if (good-enough? guess x)
		guess
		(cubic-iter (improve guess x) x)))

;(sqrt-iter 1 2)
(cubic-iter 1 -8)
