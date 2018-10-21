
// POP WRANGLE START
// https://youtu.be/cuGQnHeyJAg
int num_id_in_group(export int list[]; string geo_path) 
{ // Returns number of ids
    int c = 0;
    int result = 0;
    int counter = npoints(geo_path);
    for (int i = 0; i < counter; i++) 
    { //Agent Loop
        list[c] = point(geo_path,"id",i); // Get the ID
        c++;
    }
    return len(list);
}

int ids[]={};
vector goal_location = set(100,0,100); 
// default goal for agent 0
string geo_path = "op:/obj/crowd_sim:crowdobject/Geometry";
// Change this to your geo path.
int sl = num_id_in_group(ids, geo_path);
// Populates the list and returns the length of the array.
foreach (int c; ids)
{
    if (c>0)
    {//Exclude agent 0, we want its goal to be the default
        goal = point(geo_path, "P", ids[c-1]);
        //Goal will be the previous agent
    }
    setpointattrib(geoself(), "goal", ids[c], goal, "set"); // Set goal location to this start agent.
}
// POP WRANGLE END

// set on POP steer 
// set output to crowd steer force
goal = v@goal;
