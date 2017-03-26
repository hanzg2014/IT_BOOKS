(define phi
   (/ (+ 1 (sqrt 5)) 2))

(define (^ base exponent) 
	(if (= exponent 0) 
		1
		(* base (^ base (- exponent 1)))
	))

(define (f n)
   (/ (^ phi n) (sqrt 5)))

(f 8)