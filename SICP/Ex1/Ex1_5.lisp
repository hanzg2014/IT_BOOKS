(define (p) (p))
(define (test x y)
	(if (= x 0) 0 y))
	


; applicative order:
; (test 0 (p))
; (test 0 (p))
; (test 0 (p))
; ...
	
; normal order:
; (test 0 (p))
; (if (= x 0) 0 y)
; (if (= 0 0) 0 (p))
; (if #t 0 (p))
; 0

