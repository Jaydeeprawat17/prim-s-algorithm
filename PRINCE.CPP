#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<limits.h>
#define size 26
// we can swap node[l]=node[l+1] and l--;
//limits
//INT_MAX +32767
//INT_MIN -32768

struct Graph{
char vertex1,vertex2;
int weight;
};

struct Q{
char vertex;
int dimension;
};

class Prims_Algo{
struct Graph graph[size];
struct Q q[size],pi[size];
int edge,vertex,pi_length;
public:
Prims_Algo(){
edge=0,pi_length=0;
vertex=-1;
}
void set_Graph(){
 cout<<"Enter No of Edge: ";
 cin>>edge;
 cout<<"Enter "<<edge<<" No of vertex1,vertex2 and weight"<<endl;
  for(int s=0;s<edge;s++){
     cout<<" Enter "<<s+1<<" Vertex1 ,Vertex2 And weright:"<<endl;
     cin>>graph[s].vertex1>>graph[s].vertex2>>graph[s].weight;
     clrscr();
  }
}
int is_present_q(char v){
 if(vertex==-1)
   return 0;
  for(int s=0;s<=vertex;s++){
      if(q[s].vertex==v)
	return 1;
  }

  return 0;
}

void set_q(){
 for(int s=0;s<edge;s++){
   if(!is_present_q(graph[s].vertex1)){
       q[++vertex].vertex=graph[s].vertex1;
       q[vertex].dimension=INT_MAX;
   }
   if(!is_present_q(graph[s].vertex2)) {
     q[++vertex].vertex=graph[s].vertex2;
       q[vertex].dimension=INT_MAX;
   }

 }

}

char extract_min_q(){
 char v=q[0].vertex;
 int index=0;
 for(int s=1;s<=vertex;s++){
   if(q[index].dimension>q[s].dimension){
     v=q[s].vertex;
     index=s;
   }
 }
 // for removing selected vertex
  for(s=index;s<vertex;s++){
       q[s]=q[s+1];
  }
  vertex--;

 return v;
}

void prims(){
  char start;
  // seting all vertices and its dimension
  set_q();

  cout<<"vertex: ";
  //display vertices for user
  for(int s=0;s<=vertex;s++)
    cout<<q[s].vertex<<" ";
  cout<<endl<<"select start vertex: ";
  cin>>start;
   // set the start's dimension =0
   for(s=0;s<=vertex;s++){
     if(start==q[s].vertex){
       q[s].dimension=0;
     }
   }
   pi[pi_length].vertex=start;
   pi[pi_length++].dimension=0;

 while(vertex!=-1/*when all Q's vertices selected*/){

   start=extract_min_q();

    //finding all adjacent of u in graph
     for(s=0;s<edge;s++){
       //retriving all v form u  if v1==u  so v2==adj or v2==u so v1==adj
       if(graph[s].vertex1==start || graph[s].vertex2==start){
	  int index=-1,flag=0;
	  // finding index of v from q
	     for(int k=0;k<=vertex;k++){
		if(q[k].vertex==graph[s].vertex1||q[k].vertex==graph[s].vertex2)
		   index=k;
	      }
	      // matching condition
	    if((is_present_q(graph[s].vertex2) ||is_present_q(graph[s].vertex1))
		 &&graph[s].weight<q[index].dimension){

		//vertex1==u adj=vertex2
		if(graph[s].vertex1==start){
		   for(int j=0;j<pi_length;j++){
		     if(pi[j].vertex==graph[s].vertex2){
		      pi[j].dimension=graph[s].weight;
		       flag=1;
		     }
		   }
		 if(!flag){
		  pi[pi_length].vertex=graph[s].vertex2;
		  pi[pi_length++].dimension=graph[s].weight;
		 }
		 //vertex2 ==u  adj =vertex1
		}else if(graph[s].vertex2==start){
		  for(int j=0;j<pi_length;j++){
		     if(pi[j].vertex==graph[s].vertex1){
		       pi[j].dimension=graph[s].weight;
		       flag=1;
		     }
		   }

		 if(!flag){
		  pi[pi_length].vertex=graph[s].vertex1;
		  pi[pi_length++].dimension=graph[s].weight;

		 }
		}

	     q[index].dimension=graph[s].weight;
	   }
	}//adj if
     }
 }
//dfghjk
 for(s=0;s<pi_length;s++)
   cout<<pi[s].vertex<<" "<<pi[s].dimension<<endl;
 int len=0;
 char result[size];
 result[0]='\0';

  for(s=0;s<edge;s++){

      for(int j=0;j<pi_length;j++){
	if(graph[s].vertex2==pi[j].vertex && graph[s].weight==pi[j].dimension){
	  result[len++]=graph[s].vertex1;
	  result[len++]=graph[s].vertex2;
	  result[len]='\0';
	}
	if(graph[s].vertex1==pi[j].vertex && graph[s].weight==pi[j].dimension){
	  result[len++]=graph[s].vertex2;
	  result[len++]=graph[s].vertex1;
	  result[len]='\0';
	}
      }
  }

  cout<<"Result: "<<strupr(result)<<endl;
}


};

void main(){
clrscr();
Prims_Algo p1;
p1.set_Graph();
p1.prims();

getch();

}
