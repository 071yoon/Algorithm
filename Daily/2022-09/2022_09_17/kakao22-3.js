class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null; // 제일 앞 노드
    this.rear = null; // 제일 뒤 노드
    this.length = 0; // 노드의 길이
  }

  enqueue(data) {
    const node = new Node(data); // data를 가진 node를 만들어준다.
    if (!this.head) {
      this.head = node;
    } else {
      this.rear.next = node; // 아닐 경우 마지막의 다음 노드로
    }
    this.rear = node; // 마지막을 해당 노드로 한다.
    this.length++;
  }

  dequeue() {
    // 노드 삭제.
    if (!this.head) {
      return false;
    }
    const data = this.head.data; // head를 head의 다음 것으로 바꿔주고 뺀 data를 return
    this.head = this.head.next;
    this.length--;

    return data;
  }
  front() {
    return this.head && this.head.data;
  }
}

function solution(queue1, queue2) {
  var answer = 0;
  let sum1 = 0,
    sum2 = 0;
  const fque = new Queue();
  const sque = new Queue();
  for (let i = 0; i < queue1.length; i++) {
    fque.enqueue(queue1[i]);
    sum1 += queue1[i];
  }
  for (let i = 0; i < queue2.length; i++) {
    sque.enqueue(queue2[i]);
    sum2 += queue2[i];
  }
  for (let i = 0; i < queue1.length * 2; i++) {
    console.log(sum1, sum2);
    if (sum1 > sum2) {
      sum1 -= fque.front();
      sum2 += fque.front();
      sque.enqueue(fque.front());
      fque.dequeue();
      answer++;
    } else if (sum2 > sum1) {
      sum2 -= sque.front();
      sum1 += sque.front();
      fque.enqueue(sque.front());
      sque.dequeue();
      answer++;
    } else {
      return answer;
    }
  }
  return -1;
}
