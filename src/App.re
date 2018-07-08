type state = {repoData: option(array(RepoData.repo))};

type action =
  | FetchRepos
  | ReposFailedToFetch(string)
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {repoData: None},
  reducer: (action, _state) =>
    switch (action) {
    | FetchRepos =>
      ReasonReact.SideEffects(
        (
          self =>
            RepoData.fetchRepos()
            |> Js.Promise.then_(repoData => {
                 self.send(Loaded(repoData));
                 Js.Promise.resolve();
               })
            |> Js.Promise.catch(err =>
                 Js.Promise.resolve(
                   self.send(
                     ReposFailedToFetch(
                       "An error occurred: " ++ Js.String.make(err),
                     ),
                   ),
                 )
               )
            |> ignore
        ),
      )
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    | ReposFailedToFetch(error) =>
      ReasonReact.SideEffects((_self => Js.log(error)))
    },
  didMount: self => self.send(FetchRepos),
  render: self => {
    let repoItems =
      switch (self.state.repoData) {
      | Some(repos) =>
        ReasonReact.array(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo />,
            repos,
          ),
        )
      | None => ReasonReact.string("Loading")
      };
    <div className="App">
      <h1> (ReasonReact.string("Reason Projects")) </h1>
      repoItems
    </div>;
  },
};