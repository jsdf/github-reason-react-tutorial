type state = {repoData: option(array(RepoData.repo))};

type action =
 | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: (): state => {
    repoData: None
  },
  didMount: self => {
    let handleReposLoaded = self.reduce(repoData => Loaded(repoData));

    RepoData.fetchRepos()
      |> Js.Promise.then_(repoData => {
          handleReposLoaded(repoData);
          Js.Promise.resolve();
        })
      |> ignore;

    ReasonReact.NoUpdate;
  },
  reducer: (action, _state) => {
    switch action {
      | Loaded(loadedRepo) => ReasonReact.Update({
          repoData: Some(loadedRepo)
        })
    };
  },
  render: (self) => {
    let repoItem =
      switch (self.state.repoData) {
      | Some(repos) => ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo=repo />,
            repos
          )
        )
      | None => ReasonReact.stringToElement("Loading")
      };

    <div className="App">
      <h1>{ReasonReact.stringToElement("Reason Projects")}</h1>
      {repoItem}
    </div>
  }
};