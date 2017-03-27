; (define (gcd a b)
; 	(if (= b 0)
; 	a
; 	(gcd b (remainder a b))))


(gcd 206 40)
;(if (= b 0) a (gcd b (remainder a b)))

;normal order
;(gcd 206 40)
;(if (= 40 0) 206 (gcd 40 (remainder 206 40)))

;(if (= 40 0) 206 if (= (remainder 206 40) 0) 40 (gcd (remainder 206 40) (remainder 40 (remainder 206 40)))))

(gcd 40 (remainder 206 40))
;(if (= (remainder 206 40) 0) 40 (gcd (remainder 206 40) (remainder 40 (remainder 206 40))))
;(if (= b 0) a (gcd b (remainder a b)))


;(if (= 40 0) 206 (gcd 40 (remainder 206 40)))

;(gcd 40 (remainder 206 40)))

;applicative order
;(gcd 206 40)
;(if (= 40 0) 206 (gcd 40 (remainder 206 40)))
;(if #f 206 (gcd 40 6))

;(gcd 40 6)
;;(if (= 40 0) 40 (gcd 6 (remainder 40 6))
;(if #f 40 (gcd 6 4))

;(gcd 6 4)
;;(if (= 4 0) 6 (gcd 4 (remainder 6 4))
;(if #f 6 (gcd 4 2))

;(gcd 4 2)
;;(if (= 2 0) 4 (gcd 2 (remainder 4 2))
;(if #f 4 (gcd 2 0))

;(gcd 2 0)
;;(if (= 0 0) 2 (gcd 0 (remainder 2 0))
;(if #t 2 (gcd 0 0))



