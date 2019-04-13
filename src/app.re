[@react.component]
let make = () => {
  let (repoData, setRepoData) = React.useState(() => None);

  React.useEffect0(() => {
    RepoData.fetchRepos()
    |> Js.Promise.then_(repoData => {
         setRepoData(_prev => Some(repoData));
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(err => {
         Js.log("An error occurred: " ++ Js.String.make(err));
         Js.Promise.resolve();
       })
    |> ignore;
    None;
  });

  let repoItems =
    switch (repoData) {
    | Some(repos) =>
      ReasonReact.array(
        Array.map(
          (repo: RepoData.repo) => <RepoItem key={repo.full_name} repo />,
          repos,
        ),
      )
    | None => React.string("Loading...")
    };

  <div> <h1> {ReasonReact.string("Reason Projects")} </h1> repoItems </div>;
};