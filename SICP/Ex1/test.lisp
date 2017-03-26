(define (^ base exponent) 
	(if (= exponent 0) 
		1
		(* base (^ base (- exponent 1)))
	))


(^ 2 3)