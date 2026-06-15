# Building a work queue in Go

## Some terminology

There are a few terms we are going to be using, in this article, to describe the various parts of our queueing system.

A collector is going to be responsible for receiving work requests, and adding them to the work queue.

The work queue is, in Go terms, a buffered channel, which just lets work requests collect. The work queue is buffered, so that we do not block the collector.

Our dispatcher are responsible for pulling work requests off of the queue, and distributing them to the next available worker. To keep things clear, and voodoo-free, we are going to have our dispatcher maintain several queues, the first of which, being the worker queue.

The worker queue is the weirdest part about all of this (if you are not familiar with Go, and maybe, even if you are). It is a buffered channel of channels. The channels that go into this channel, are what the workers use to receive the work request. If this does not make sense now, it probably will as we implement the system.
