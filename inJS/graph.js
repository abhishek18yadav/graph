class node{
    constructor(val){
        this.val = val;
        this.next  =null;
        this.prev = null;
    }
}

class linkedlist{
    constructor(val){
        this.head= null;
        this.tail = null;
    }
    addattail(node){
        if(this.head==null){
            this.head=node;
            this.tail= node;
            return;
        }else{
            let temp = node;
            this.tail.next=temp;
            temp.prev = this.tail;
            this.tail= temp;
            
        }
    }
    deleteathead(){
        let temp= this.head;
        if(this.head== null)return ;
        // if size is 1
        if(this.head.next==null){
            this.head= null;
            this.tail=null;
        }
        else{
            this.head= this.head.next;
            temp.next= null;
            this.head.prev= null;
        }
    }
    dis(){
        if(this.head==null){
            console.log("empty");
            return;
        }
        let temp = this.head;
        while(temp){
            console.log(temp.val);
            temp= temp.next;
        }
    }
}



class queue{
    constructor(){
        this.dll = new linkedlist();
        this.size =0;
    }
    front(){
        if(this.dll.head == null)return null;
        else return this.dll.head.val;
    }
    push(val){
        let newval = new node(val);
        this.dll.addattail(newval); 
        this.size++;
    }
    pop(){
        this.size--;
        this.dll.deleteathead();
    }
    empty(){
        if(this.size==0)return true;
        else return false;
    }
    d(){
        while(this.empty()==false){
            console.log(this.front());
            this.pop();
        }
    }
}



class graph{
    constructor(v){
        this.v= v;
        this.arr = new Array(this.v);
        for(let i=0; i<this.v; i++){
            this.arr[i]= [];
        }
    }
    display(){
        console.log(this.arr);
    }
    add_edge(s,d,bi_dir = false){
        this.arr[s].push(d);
        if(bi_dir){
            this.arr[d].push(s);
        }
    }
    bfs(s){
        let qu = new queue();
        qu.push(s);
        let st = new Set();
        st.add(s);
        while(!qu.empty()){
            let node = qu.front();
            qu.pop();
            for(let neigh of this.arr[node]){
                if(!st.has(neigh)){
                    st.add(neigh);
                    qu.push(neigh);
                    console.log(neigh);
                }
            }
        }
    }
    dfs(s, visited){
        console.log(s);
        for(let neigh of this.arr[s]){
            if(visited.has(neigh))continue;
            visited.add(neigh);
            this.dfs(neigh , visited);
        }
    }
}
let g = new graph(7);
g.add_edge(0,1);
g.add_edge(0,6);
g.add_edge(6,5);
g.add_edge(1,5);
g.add_edge(1,2);
g.add_edge(2,4);
g.add_edge(2,3);
g.add_edge(4,3);
g.display();
g.bfs(0);
var visited = new Set();
visited.add(0);
// g.dfs(0,visited);

// let ll = new linkedlist();
// let n1 = new node(2);
// ll.addattail(n1);
// let n2 = new node(1);
// ll.addattail(n2);
// let n3 = new node(6);
// ll.addattail(n3);
// let n4 = new node(7);
// ll.addattail(n4);
// ll.dis();
// ll.deleteathead();
// ll.dis();
// let q = new queue();
// q.push(1);
// q.push(2);
// q.push(3);
// q.push(4);
// q.push(5);
// q.push(6);
// q.pop();

// q.d();
