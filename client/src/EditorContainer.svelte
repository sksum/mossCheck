<script>
    import Editor from './Editor.svelte'
    export let lang = "cc"; 
    let moss = (ev, strA, strB) => {
        const URL = '/hello'
        fetch(URL,{
            headers: {
            'Content-Type': 'application/json'
            },
            method: 'POST',
    
            // A JSON payload
            body: JSON.stringify({
                "greeting": "Hello from the browser!",
                "fileA":strA,
                "fileB":strB,
                "lang":lang,
                "userId":document.getElementById("userID").value
            })
        }).then(function (response) { 
                return response.text();
            }).then(function (text) {
                var result = JSON.parse(text);
                console.log(result);
                document.getElementById("url").textContent = result.url
                document.getElementById("url").href = result.url
            });
    }
</script>

<div id="editors">
    <table>
        <tbody>
            <th>
                <Editor id="editorA" {lang} />
            </th>
            <th>
                <Editor id="editorB" {lang} />
            </th>
        </tbody>
    </table>
</div>
<button id="Moss" on:click ={(ev)=>moss(ev,document.getElementById("editorA").textContent,document.getElementById("editorB").textContent)}>Moss</button>
<a id ="url" target="_blank"></a>

<style>
    table {
        table-layout: fixed;
        width:100%;
    }
    button {
        width:10%;
        margin-left:45%;
        margin-right:45%;    
    }
    a {
        display: flex;
        justify-content: center;
    }
</style>