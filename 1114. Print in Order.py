from threading import Semaphore

class Foo:
    def __init__(self):
        self.s1=Semaphore(0)
        self.s2=Semaphore(0)


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.s1.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.s1:
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
            self.s2.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.s2:
            # printThird() outputs "third". Do not change or remove this line.
            printThird()