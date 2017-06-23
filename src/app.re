
type component_state = {repos: option (array RepoData.repo)};

let component = ReasonReact.statefulComponent "App";

let handleReposLoaded repos _state _self => {
  ReasonReact.Update {
    repos: Some repos
  };
};

let make ::title _children => {
  ...component,
  initialState: fun () :component_state => {
    repos: None
  },
  didMount: fun _state self => {
    RepoData.fetchRepos ()
      |> Js.Promise.then_ (fun repos => {
          (self.update handleReposLoaded) repos;
          Js.Promise.resolve ();
        })
      |> ignore;

    ReasonReact.NoUpdate;
  },
  render: fun state _self => {
    let repoItem = switch (state.repos) {
      | Some repos => ReasonReact.arrayToElement (Array.map
          (fun (repo: RepoData.repo) => <RepoItem key=repo.full_name repo=repo />) repos
        )
      | None => ReasonReact.stringToElement "Loading"
    };
    <div className="App">
      <div className="App-header"> <h1> (ReasonReact.stringToElement "Reason Projects") </h1> </div>
      repoItem
    </div>
  }
};
